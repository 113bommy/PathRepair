for _ in range(int(input())):l,s=sorted(map(int,input().split()));print(*([-1,-1],[l,l*2])[l*2<=s])
