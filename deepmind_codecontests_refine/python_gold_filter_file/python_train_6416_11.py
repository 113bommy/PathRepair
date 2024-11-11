n = int(input())
mod = n%10

if mod < 5 : print(n-mod)
elif mod >= 5: print(n+(10-mod))
else : print(n)