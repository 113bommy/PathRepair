a = int(input())
print(('{0} {1}'.format(a//2 - 1, a//2 +1) if (a%2)%2 == 0 else '{0} {1}'.format(a//2 - 2, a//2 + 2)) if a%2 == 0 else '{0} {1}'.format(a//2 , a//2 +1) )