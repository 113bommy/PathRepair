n=int(input())
s=input()
red=s.count('r')
print(red-s[:red].count('r'))