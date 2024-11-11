#%% 1284a New Year and naming 
input()
s = list(input().split())
t = list(input().split())
for num in [int(input()) for _ in ' '*int(input())]:
    print(s[num%len(s)] + t[num%len(t)])