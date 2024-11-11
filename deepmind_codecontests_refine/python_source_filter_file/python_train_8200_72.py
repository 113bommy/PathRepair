n = int(input())
s = set(map(int,input().split()))
print('YNeos'[n!=len(s)::2])