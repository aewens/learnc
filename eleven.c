#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char *name;
    int health;
    int attack;
    int defense;
};

struct Player *Player_create(char *name, int health, int attack, int defense)
{
    struct Player *who = malloc(sizeof(struct Player));
    assert(who != NULL);
    
    who->name = strdup(name);
    who->health = health;
    who->attack = attack;
    who->defense = defense;
    
    return who;
}

void Player_destroy(struct Player *who)
{
    assert(who != NULL);
    
    free(who->name);
    free(who);
}

void Player_print(struct Player *who)
{
    printf("Name: %s\n", who->name);
    printf("\tHealth: %d\n", who->health);
    printf("\tAttack: %d\n", who->attack);
    printf("\tDefense: %d\n", who->defense);
}

int main(int argc, char *argv[])
{
    struct Player *player1 = Player_create("Blob", 10, 2, 1);
    struct Player *player2 = Player_create("Bleb", 8, 2, 3);
    
    printf("Player1 is at memory location: %p\n", player1);
    Player_print(player1);
    
    printf("Player2 is at memory location: %p\n", player2);
    Player_print(player2);
    
    // Boom! Pow!
    player1->health -= 3;
    player1->defense = 0;
    Player_print(player1);
    
    player1->health -= 1;
    player2->defense = 0;
    Player_print(player2);
    
    // Game Over!
    Player_destroy(player1);
    Player_destroy(player2);
    
    return 0;
}
