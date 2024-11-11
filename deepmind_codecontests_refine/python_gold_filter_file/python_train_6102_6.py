n = int(input());
l = list();
s = input();
l = s.split(' ',n-1);
for i in range(len(l)):
    l[i]=int(l[i]);

if((l[0]% 2 == 1)&(l[len(l)-1]% 2 == 1)&len(l)): print("Yes");
else: print("No");            