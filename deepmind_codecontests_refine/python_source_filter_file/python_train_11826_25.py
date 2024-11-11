import math;

n = int(input());
mass = [int(i) for i in input().split()];

list.sort(mass);

min = math.fabs(mass[0]-mass[1]);

old = 0;
i = 1;
k = 1;

while i < len(mass):
    summ = math.fabs(mass[old]-mass[i]);
    
    if (min > summ):
        k = 1;
        min = summ;
    elif (min == summ):
        k+=1;
    old = i;
    i+=1;

print(int(min),int(k));