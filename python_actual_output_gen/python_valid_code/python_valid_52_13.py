t=int(input())
for _ in range(t):
    input()
    s=input()
    print("YNEOS" [len(s)==len(set(s))::2])