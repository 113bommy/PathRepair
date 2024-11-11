colors=input().split()
colors=set(colors)

result=(4-len(colors))

print(int(result) if result>=0 and result<=4 else '0')
    