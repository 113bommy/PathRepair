n = int(input())
s = set(map(int,input().split()))
print('YNEOS'[n!=len(s)::2])
