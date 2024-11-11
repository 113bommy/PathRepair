n=input()
s=input()
one=s.count('n')
zero=s.count('z')
ans=['1' for i in range(one)]
ans+=['0' for i in range(zero)]
print (''.join(ans))