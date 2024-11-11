n = input()
print('%05d'%(pow(int(''.join([n[0],n[2],n[4],n[3],n[1]])), 5)%100000))
