#%% 1437a Marketing scheme 
for _ in range(int(input())):
    l,r = map(int,input().split())
    print('YNEOS'[r>2*l::2])
    