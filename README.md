# UTF-8 Texas Hold'em
A c++ program to play Texas Hold'em against 3 computer players using UTF-8 characters to
draw the user interface. UTF-8 is required to play this in your console. The program has only 
been tested in a linux environment.

## TODO
* Add Winning Hand Logic, and translate to WinningHandDisplay
* Implement betting rules, and translate to a running update in the TextBoxDisplay
* Implement a rudimentary ai.
* Add multi-platform screen clearing capability.

### 2016-07-07 Screen Shots
#### Ante
The logic for drawing the winning row is implemented, hence the cards with . instead of values. This row will be blank After the winning logic is implemented. At the win screen, the cards involved in the winning hand will be bumped up to the winning row, with the winners Showdown cards at the far right.
![](screenshots/2016-07-07_GameStart.png)  

#### PreFlop
![](screenshots/2016-07-07_PreFlop.png)

#### Flop
![](screenshots/2016-07-07_Flop.png)

#### Turn
![](screenshots/2016-07-07_Turn.png)

#### River
![](screenshots/2016-07-07_River.png)

#### Winning Screen sans the Winning Row
![](screenshots/2016-07-07_WinScreen_SansWinningRow.png)

#### Losing Screen sans the Winning Row
![](screenshots/2016-07-07_LoseScreen_SansWinningRow.png)
