import sys
import math

def fn(s,k,w):
    l = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    x = [[0]*2]*26
    for i in range(len(x)):
        x[i] = [l[i],int(w[i])]
    y = x.copy()
    x.sort(key = lambda x: x[1], reverse = True)
    s = list(s)
    sum=0
    first_tuple_elements = []
    second_tuple_elements = []
    for a_tuple in y:
        first_tuple_elements.append(a_tuple[0])
    for b in y:
        second_tuple_elements.append(b[1])
    for i in range(len(s)):
        sum = sum + (i+1)*int(second_tuple_elements[first_tuple_elements.index(s[i])])
    z = x[0][1]
    sum1 = sum + (k*(k+1)/2 + k*len(s))*z
    return float(sum1)

if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(str, input.split()))
    s = data[0]
    k = int(data[1])
    w = (data[2:])
    print(fn(s,k,w))
    