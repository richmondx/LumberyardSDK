PlayFab Amazon Lumberyard SDK Getting Started Guide
========
Welcome to the PlayFab Amazon Lumberyard SDK.

In this guide, we will describe making your first PlayFab Api call using the PlayFabClientSdk.

1. Prerequisites:
----

1. [Install lumberyard](https://aws.amazon.com/lumberyard/downloads/)
2. Read and finish the "Programming" section in this link to learn how to set up your Lumberyard development environment: https://gamedev.amazon.com/forums/tutorials
3. Please follow steps 2 and 3 in the Readme to get Lumberyard and the PlayFab Sdk installed:
 * https://github.com/PlayFab/LumberyardSDK/blob/master/README.md#2-prerequisites
 * https://github.com/PlayFab/LumberyardSDK/blob/master/README.md#3-gem-installation
4. It is expected that you have read and understand all "Programming" tutorials on this page: https://gamedev.amazon.com/forums/tutorials

2. Your Lumberyard Gem
----

* There is an excellent tutorial on creating your own gem labeled "Creating A Gem With Code" on this page:
 * https://gamedev.amazon.com/forums/tutorials
* Before you proceed, you must have your own gem set up, and it is highly suggested you have a OnPostUpdate function printing text to the screen.
* After you have set up your own gem, Follow step 4 in the Readme to add a dependency to the PlayFabSdk gem, and enable PlayFab api calls in your gem:
 * https://github.com/PlayFab/LumberyardSDK/blob/master/README.md#4-gem-dependency
* At this point you are ready to make your first api call

3. Prepare your gem to report API-Call results:
----

This part of the guide is an extension of the "Creating A Gem With Code" Amazon tutorial.  You will add a static string to your gem, and update your OnPostUpdate function to print that string.

The code below is an example of how to change your tutorial Gem to print a statically defined block of text.  Later, we will modify that text with a PlayFab API call.

PlayFabApiTestGem.h (Rename "PlayFabApiTestGem" with your own gem name)
```
#pragma once

#include "IPlayFabApiTestGem.h"
#include <aws/core/utils/memory/stl/AWSString.h> // <--------- ADD THIS LINE
#include <IGameFramework.h>

namespace PlayFabApiTest
{
    class PlayFabApiTestGem : public IPlayFabApiTestGem, IGameFrameworkListener
    {
        ... other gem header code ...
        void OnPostUpdate(float fDeltaTime) override; // <--------- If you followed the tutorial, this line should already exist

        static Aws::String lastDebugMessage; // <--------- ADD THIS LINE TO YOUR GEM
    };
} // namespace PlayFabApiTest
```

PlayFabApiTestGem.cpp (Rename "PlayFabApiTestGem" with your own gem name)
```
... other gem code ...

Aws::String PlayFabApiTest::PlayFabApiTestGem::lastDebugMessage; // <--------- ADD THIS LINE

void PlayFabApiTest::PlayFabApiTestGem::OnPostUpdate(float fDeltaTime) // <--------- If you followed the tutorial, this function should already exist
{
    if (lastDebugMessage.length() > 0)
    {
        float white[4] = { 1.f, 1.f, 1.f, 1.f };
        gEnv->pRenderer->Draw2dLabel(32.f, 32.f, 2.f, white, false, lastDebugMessage.c_str());
        // If you followed the tutorial,
        //   you only need to change the text “Hello World Gem says hello.”, to:
        //   lastDebugMessage.c_str()
    }
}
```

4. Adding a login Api call to your gem:
----

In this section we will add the code that makes an API call, and activate that code from the setup function of our Gem.

PlayFabApiTestGem.h (Rename "PlayFabApiTestGem" with your own gem name)
```
#pragma once

... Other includes ...
#include <PlayFabClientDataModels.h> // <--------- ADD THIS LINE

namespace PlayFabApiTest
{
    class PlayFabApiTestGem : public IPlayFabApiTestGem, IGameFrameworkListener
    {
        ... other gem header code ...
        static void PlayFabLogin(); // <--------- ADD THIS LINE
        static void LoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData); // <--------- ADD THIS LINE
        static void LoginFail(const PlayFab::PlayFabError& error, void* customData); // <--------- ADD THIS LINE
    };
} // namespace PlayFabApiTest
```

PlayFabApiTestGem.cpp (Rename "PlayFabApiTestGem" with your own gem name)
```
... other gem code ...

// ---------------- Add all of this code to your gem.cpp file ---------------- 
void PlayFabApiTest::PlayFabApiTestGem::PlayFabLogin()
{
    auto playFabSdkGem = GetISystem()->GetGemManager()->GetGem<PlayFab::IPlayFabSdkGem>();
    if (!playFabSdkGem)
    {
        lastDebugMessage = "Error in project: Cannot find PlayFab Gem";
        return;
    }
    auto clientApi = playFabSdkGem->GetClientApi();

    PlayFab::ClientModels::LoginWithCustomIDRequest request;
    request.CreateAccount = true;
    request.CustomId = "PlayFabSdkTutorial";
    clientApi->LoginWithCustomID(request, LoginSuccess, LoginFail);
}
void PlayFabApiTest::PlayFabApiTestGem::LoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData)
{
    lastDebugMessage = "Login success: " + result.PlayFabId;
}
void PlayFabApiTest::PlayFabApiTestGem::LoginFail(const PlayFab::PlayFabError& error, void* customData)
{
    lastDebugMessage = "Login failed: " + error.ErrorMessage;
}
```

PlayFabApiTestGem.cpp (Rename "PlayFabApiTestGem" with your own gem name)
```
... other gem code ...
void PlayFabApiTest::PlayFabApiTestGem::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
    ... other gem code ...
    case ESYSTEM_EVENT_GAME_POST_INIT:
        if (gEnv->pGame->GetIGameFramework())
            gEnv->pGame->GetIGameFramework()->RegisterListener(this, "PlayFabSdk Gem", FRAMEWORKLISTENERPRIORITY_HUD);
        PlayFabLogin(); // <--------- ADD THIS LINE
        break;
    ... other gem code ...
}
```

While following the Amazon tutorial instructions you should have already done several steps.  Double check them now:
* Your build configuration should be:  "[All] Debug" or "[All] Release"
* Your build platform should be: "x64"
Finally, build and run your project:
* You should have set the "Sandbox/Editor" project as your startup project (under the solutuion, Editor project should be bold)
* Dropdown->Build->Build solution.  The first time you do this, it will take a long time.
* Run the Editor project (Usually F5).  The first time you do this, the Asset Processor will appear, and will also take a long time.
* TODO: Almost done - This section will be complete very soon. ADD STEPS HERE: load a project, Ctrl+G to start, verify text output

Finally, the request.CustomId for this example is hard-coded.  For a real game, you may want to use a unique string as the customId for each player, or use one of our other [Client authentication apis](https://api.playfab.com/Documentation/Client) with proper information.

4. Troubleshooting:
----

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/hc/en-us)


5. Copyright and Licensing Information:
----
  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.

