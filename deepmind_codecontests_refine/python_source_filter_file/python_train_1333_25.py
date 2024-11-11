li=[int(input()) for i in range(5)]
lic=[10-it%10 for it in li]
print( sum(li)+sum(lic)-max(lic) ) 