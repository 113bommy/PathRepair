n=int(input())
s=input()
red=s.count('R')
print(red-s[:red].count('R'))
