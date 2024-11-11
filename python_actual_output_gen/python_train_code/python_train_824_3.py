n=int(input())
x=[int(x) for x in input().split()]
print('{} {}'.format(abs(x[0]-x[n-1]), abs(x[0]-x[1])))
for i in range(1,n-1):
  print('{} {}'.format(min(abs(x[i]-x[i-1]), abs(x[i]-x[i+1])),
                       max(abs(x[i]-x[n-1]), abs(x[i]-x[0]))))

print('{} {}'.format(abs(x[n-1]-x[n-2]), abs(x[0]-x[n-1])))
