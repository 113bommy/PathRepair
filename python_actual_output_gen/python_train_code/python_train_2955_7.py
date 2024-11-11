n = int(input())

if n == 8:
    print("Vaporeon")
elif n == 6:
    print("Espeon")
else:
    l = {'Jolteon', 'Flareon', 'Umbreon', 'Leafeon', 'Glaceon', 'Sylveon'}
    ans = set()
    s = input().capitalize()
    for i in range(n):
        if s[i] != ".":
            for j in l:
                if s[i] == j[i]:
                    ans.add(j)
            if ans:
                l = l.intersection(ans)
                ans = set()
                
    if len(l) == 1:
        for i in l:
            print(i.lower())
