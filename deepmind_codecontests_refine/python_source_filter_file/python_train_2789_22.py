gomi=input()
tako=[int(i) for i in input().split()]
print((sum(tako)**2-sum([i**2 for i in tako]))/2)  