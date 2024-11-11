N = int(input())
s = input()

init = ["SS", "SW", "WS", "WW"]
next_animal = { ("S","o","S"):"S",
                ("S","o","W"):"W",
                ("S","x","S"):"W",
                ("S","x","W"):"S",
                ("W","o","S"):"W",
                ("W","o","W"):"S",
                ("W","x","S"):"S",
                ("W","x","W"):"W"}
for X in init:
    SW = X
    for i in range(1,N):
        SW += next_animal[SW[i],s[i],SW[i-1]]
    ls = len(SW)
    if SW[0] == SW[ls-1] and next_animal[SW[0],s[0],SW[ls-1]] == SW[1]:
        print(SW[:ls-1])
        break
else:
    print(-1) 
