print(*[''.join(str(i)+'x'+str(j)+'='+str(i*j)) for j in range(1,10) for i in range(1,10)], sep='\n')
