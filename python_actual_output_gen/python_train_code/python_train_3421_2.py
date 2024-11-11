sus = int(input()); piss = list(map(int,input().split()))
ass = sorted(piss); shit = 0
for fef in range(sus):
    if piss[fef]!=ass[fef]: shit += 1
print("YES" if shit//2 < 2 else "NO")