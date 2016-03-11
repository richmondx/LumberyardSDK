PlayFab Amazon Lumberyard SDK Getting Started Guide
========
Welcome to the PlayFab Amazon Lumberyard SDK.

In this guide, we will describe making your first PlayFab Api call using the PlayFabClientSdk.

1. Prerequisites:
----

1. [Install lumberyard](https://aws.amazon.com/lumberyard/downloads/)
2. Read and finish the "Programming" section in this link to learn how to set up your Lumberyard development environment: https://gamedev.amazon.com/forums/tutorials
3. Please follow steps 2 and 3 in the  to get Lumberyard and the PlayFab Sdk installed
4. It is expected that you have read and understand all "Programming" tutorials on this page: https://gamedev.amazon.com/forums/tutorials

2. Your Lumberyard Gem
----

There is an excellent tutorial on creating your own gem labeled "Creating A Gem With Code" on this page: https://gamedev.amazon.com/forums/tutorials
Before you proceed, you must have your own gem set up, and it is highly suggested you have a OnPostUpdate function printing text to the screen.

After you have set up your own gem, Follow step 4 in the [Readme](README.md) to add a dependency to the PlayFabSdk gem, and enable PlayFab api calls in your gem.

At this point you are ready to make your first api call

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

TODO: Almost done - This section will be complete very soon.

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

