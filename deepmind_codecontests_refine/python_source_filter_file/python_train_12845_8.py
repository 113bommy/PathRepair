n,k = [int(i) for i in input().split(' ')]

def down():
    if k>=n*(n-1)/2:
        print('No solution')
        return 
    else:
        i,j=0,0
        ar=[(i,j)]
        for j in range(1, n):
            ar.append((i,j))
        for i in ar:
            print('%s %s' %i)

down()
