# SZE-MOSZE-2020-MarGit

A program 3 json fájlból olvassa be a characterek tulajdonságait a parseUnit metódus segítségével, majd egy output.txt-be tölti be az eredményt.
A hozzáadott workflow gondoskodik arról, hogy a program upgrade/update-je csak akkor kerülhessek GH-ra, ha az lefordul és az output-ja megegyezik az előre kiszámolt result-tal.

A Character.cpp fájlban található az Character osztály. 
    Attribútumok: name, hp, damage.
    Metódusok: konstruktor,attack, isDead, parseUnit.

A Source.cpp megvizsgálja, hogy a json fileok megnyitásakor történik-e hiba, majd ha megfelelő fileokat kap, létrehoz két Character objektumot és átadja az auto_combat függvénynek, különben pedig -99 hibakódot dob vissza.
A program addig fut, míg az auto_combat-nak adott két karakter közül az egyik élete el nem éri a 0-t
