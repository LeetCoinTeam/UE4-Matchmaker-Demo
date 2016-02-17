# UE4-Matchmaker-Demo
LEET Matchmaker game demo. 

Full How-to coming soon!

Objective:

Build a game in Unreal Engine 4 which uses the LEET matchmaker service.

Detail:

LEET provides a simple matchmaker API endpoint, which allows UE4 developers to focus on gameplay and avoid external server maintenance and user authentication hassles.

Strategy:

We will be building a simple 2 player game.  The players will meet on the leet website.  When they sign up for a match, a new dedicated server will be created and configured.  The players will then connect to the server instance.  A coin will represent the WIN state, and the first player to collect the coin will win the match.  The dedicated server then notifies the leet website, and the player's ranks and other settings are modified.

Requirements:

A developer account on the LEET sandbox:   leetsandbox.appspot.com
Unreal Engine 4.11 or higher built form the github source.
Windows 7 or higher with MS Visual Studio 2015