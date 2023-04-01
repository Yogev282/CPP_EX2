// #include "doctest.h"
// #include <sstream>
// #include <stdexcept>
// #include "sources/player.hpp"
// #include "sources/game.hpp"
// #include "sources/card.hpp"

// using namespace ariel;

// TEST_CASE("Test Card class") { 
   
//     Card c1(1, "Hearts");
//     Card c2(13, "Diamonds");
//     Card c3(1, "Clovers");
//     Card c4(2, "Pikes");
//     Card c5(7, "Diamonds");

//     CHECK(c1.compareto(c2) == -1);
//     CHECK(c1.compareto(c4) == -1);
//     CHECK(c1.compareto(c3) == 0);
//     CHECK(c5.compareto(c1) == 1);
//     CHECK(c2.compareto(c2) == 0);
// }

// TEST_CASE("Test Player class") {
//     SUBCASE("Test addCard and stacksize") {
//         Player p("Alice");
//         CHECK(p.stacksize() == 26);
//         CHECK(p.cardesTaken() == 0);
//         Card c1(1, "Hearts");
//         Card c2( 11 , "Diamonds");
//         Card c3(10, "Pikes");
//         p.addCardtoEnd(c1);
//         p.addCardtoEnd(c2);
//         p.addCardtoEnd(c3);
//         CHECK(p.stacksize() == 29);
//         CHECK(p.cardesTaken() == 3);
//         p.playCard();
//         CHECK(p.stacksize() == 28);

//         p.playCard();
//         p.playCard();
//         CHECK(p.stacksize() == 26);
        
//     }
// }



// TEST_CASE("Test While playing") {
//     SUBCASE("normal game"){
//         Player p1("Alice");
//         Player p2("Bob");

//         Game g(p1, p2);

//         // CHECK(g.printWiner() == "No one");

//         p1.addCardtoStart(Card(13, "Pikes"));
//         p1.addCardtoStart(Card(10, "Hearts"));
//         p1.addCardtoStart(Card(5, "Hearts"));

//         p2.addCardtoStart(Card(1, "Hearts"));
//         p2.addCardtoStart(Card(12, "Hearts"));
//         p2.addCardtoStart(Card(5, "Diamonds"));

//         g.playTurn();
//         string s = g.printLastTurn();
//         CHECK(s == "Alice played 5 of Hearts Bob played 5 of Diamonds. Draw. Alice played 13 of Pikes Bob played 1 of Hearts. Alice  wins.");
//         CHECK(p1.cardesTaken() == 3);

//         g.playAll();

//         Player w("Winner");
//         Player l("Loser");

//         if(p1.stacksize() == 0) {
//             // string winner = g.printWiner();
//             // CHECK(winner == "Bob");
//             w = p2;
//             l = p1;
//         } else {
//             // string winner = g.printWiner();
//             // CHECK(winner == "Alice");
//             w = p1;
//             l = p2;
//         };

//         CHECK(w.cardesTaken() >= 26);
//         CHECK(w.stacksize() == 52);
//         CHECK(l.cardesTaken() == 0);
//         CHECK(l.stacksize() == 0);

//         CHECK_THROWS(g.playTurn());
//     }


//     SUBCASE("ends by equal"){
//         Player p1("Alice");
//         Player p2("Bob");
//         Game g(p1, p2);

//         // CHECK(g.printWiner() == "No one");

//         g.playAll();

//         Player w("Winner");
//         Player l("Loser");

//         if(p1.stacksize() == 0) {
//             w = p2;
//             l = p1;
//         } else {
//             w = p1;
//             l = p2;
//         }

//         w.addCardtoStart(Card(1, "Clubs"));
//         w.addCardtoStart(Card(10, "Hearts"));
//         w.addCardtoStart(Card(5, "Hearts"));

//         l.addCardtoStart(Card(1, "Hearts"));
//         l.addCardtoStart(Card(12, "Hearts"));
//         l.addCardtoStart(Card(5, "Diamonds"));

//         g.playTurn();

//         string s = g.printLastTurn();

//         CHECK(s == "Alice played 5 of Hearts Bob played 5 of Diamonds. Draw. Alice played 1 of Clubs Bob played 1 of Hearts. Draw.");

//         CHECK(l.stacksize() == 3);
//         CHECK(w.stacksize() == 49);

//         g.playAll();
//         CHECK_THROWS(g.playTurn());
        
        

//     }
    
    
// }
