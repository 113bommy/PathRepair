import time
input()
_inp = list(map(int,(input('').split())))
mi = min(_inp)+1
i=mi
ma=max(_inp)
def find_the_last(_inp):
    result=0
    for y in _inp:
        if (abs(i-y)>1):
            result += abs(i-y)-1
    return result

result= find_the_last(_inp)
while i<ma:
    pre_result = find_the_last(_inp)
    if pre_result<result:
        result,mi = pre_result,i
    i+=1    

print(mi,result)
