import math



def main_function():
    pokemons = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
    n = int(input())
    s = input()
    pokemon_is_found = False
    for pokemon in pokemons:
        if len(pokemon) != len(s):
            continue
        #print("korea")
        for i in range(len(pokemon)):
            #print(i)
            if s[i] != ".":
                if s[i] != pokemon[i]:
                    break
            if i == len(pokemon) - 1:
                    pokemon_is_found = True
                    print(pokemon)
                    break
        if pokemon_is_found:
            break











main_function()
