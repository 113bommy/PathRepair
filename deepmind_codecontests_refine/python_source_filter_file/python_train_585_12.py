import math
 
k,d,t = map(int, input().split())
 
timegap = (((k - 1)//d) + 1) * d
donefull = k;
donehalf = (timegap - k) / 2.0
done = 0
timer = 0   
x = math.floor(t / (donefull + donehalf))
timer = x * timegap
done = x * (donefull + donehalf)
left = t - done
if left <= k:
    timer += left
else:
    timer += left;
    left -= k;
    timer += (left + left);
print(timer)