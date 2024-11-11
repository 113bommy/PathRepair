n=int(input())
home=input()
for i in range(n-1):
    s=input()
s1=input().split('->')
if s1[1]==home:
    print('home')
else:
    print('contest')