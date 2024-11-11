S,C=map(int,input().split())

if 2*S>=C:
    print(C//2)
else:
    print(S+((C-2*S)//4))
