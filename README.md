PlayFab Amazon Lumberyard SDK README
========
Welcome to the PlayFab Amazon Lumberyard SDK.


1. Overview:
----
This document describes the PlayFabSdk Lumberyard Gem, and usage.

The Lumberyard SDK will give you the ability to call any public PlayFab API from a Lumberyard project.

The PlayFab platform runs on AWS, and PlayFab has express permission from Amazon to provide services for Lumberyard.


2. Prerequisites:
----
* Install Lumberyard: https://aws.amazon.com/lumberyard/downloads/
 * Fully unpacked and installed, Lumberyard will need at least 50-80 gigabytes of space
  * This does not include the files specific to your project, which may be 5-20 additional gigabytes (or more, depending on your project)
  * The PlayFab SDK adds approximately 1 mb
 * Follow the instructions on acceptable directory requirements for your Lumberyard install location: {LumberyardLocation}
* Install Visual Studio (2013 or 2015)
* Follow the Lumberyard setup instructions here: https://gamedev.amazon.com/forums/tutorials
 * Specifically "Installing and Configuring Lumberyard"
 * PlayFab does not specifically require any art, animation, or video editing programs, however it is very likely that you will need them to make your game.
 * All other plugins, sdks, and other mandatory software is probably required
* Follow the "Programming" series of tutorials to set up your Lumberyard environment (halfway down the page, search for "Programming")
 * https://gamedev.amazon.com/forums/tutorials

Users should be very familiar with the topics covered in our [getting started guide](https://playfab.com/docs/getting-started-with-playfab/).
To connect to the PlayFab service, your machine must be running TLS v1.2 or better.
* For Windows, this means Windows 7 and above
* [Official Microsoft Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa380516%28v=vs.85%29.aspx)
* [Support for SSL/TLS protocols on Windows](http://blogs.msdn.com/b/kaushal/archive/2011/10/02/support-for-ssl-tls-protocols-on-windows.aspx)


3. Gem Installation:
----
For building the game client, distributed to the End-User, you must only use the PlayFabClientSDK.

A game server is not required for all games, however many online games require online server architecture.  PlayFab also does not require you to use the same SDK for client and server.
If your game-server is a separate stand-alone console application, it is possible to use the [C++ WindowsSDK](https://github.com/PlayFab/WindowsSDK).
If your game-server requires an the game environment, you can also use the PlayFabServerSDK provided with in the Lumberyard SDK.
Do not mix the client/server/combo files, or your project may not compile.

To implement both client and server in Lumberyard, you must create two separate projects, and install each gem separately.  Do not publish any project containing your DeveloperSecretKey - For security reasons you must never expose this value to players

* After you finish the Lumberyard setup steps in the section above, you will need to download the PlayFab gem.
 * If you are reading this document, you probably already have it, but you can also find it here: https://api.playfab.com/sdks/LumberyardSdk/
* The rest of this document assumes you will use the Client-Api in your Lumberyard project: https://api.playfab.com/Documentation/Client
 * Instructions for Server/Combo are similar
* Download and extract the Lumberyard SDK to a temporary folder: {tempPlayFabSdkLocation}
* Copy/Paste the {tempPlayFabSdkLocation}/PlayFabClientSdk folder into your lumberyard project, specifically to: {LumberyardLocation}/dev/Gems/PlayFabClientSdk
 * Rename {LumberyardLocation}/dev/Gems/PlayFabClientSdk to {LumberyardLocation}/dev/Gems/PlayFabSdk
* Follow these screenshots to configure lumberyard to include the PlayFabSdk Gem
 * ![1_Launcher](LumberTutorial/1_Launcher.png)
 * ![2_SetupGems](LumberTutorial/2_SetupGems.png)
 * ![3_EnablePlayFab](LumberTutorial/3_EnablePlayFab.png)

  
4. Gem-Dependency:
----
If you create your own Gem, you can access PlayFab by adding a Gem-dependency in your gem.json file.
* Navigate to: {LumberyardLocation}/dev/Gems/{YourGem}/gem.json
* Use this guide to add a dependency to PlayFab: http://docs.aws.amazon.com/lumberyard/latest/userguide/gems-system.html
 * Example:

```
    "Dependencies": [
        {
            "Uuid": "9a81e5573c13455b850560486e4e7d05",
            "VersionConstraints": [ ">=0.0.160302" ],
            "_comment": "PlayFab Lumberyard Gem"
        }
    ]
```


5. Troubleshooting:
----
In the future, if you update your PlayFabSdk to a new version, Lumberyard may crash on startup. Rerun the "Follow these screenshots to configure lumberyard to include the PlayFabSdk Gem" steps to resolve the issue

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/hc/en-us)


6. Copyright and Licensing Information:
----
  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.

