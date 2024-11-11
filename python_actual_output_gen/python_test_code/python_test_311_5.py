def get_input():
    num = input()
    line = input()
    test_cases = line.split()
    result = []
    for i in test_cases:
        result.append(int(i))
    return result

def send_balls(n,l):
    l = sorted(l)
    l2 = l.copy();
    for x in range(0,n-2):
        if l[x]==l[x+1]:
            l2.remove(l[x+1])
    else:
        for i in range(0,len(l2)-2):
            if l2[i+1]-l[i]<2 and l2[i+2]-l[i+1]<2 and l2[i+1]!=l[i] and l2[i+2]!=l[i+1]:
                return "YES";
    return "NO";


test_cases = get_input()
print(send_balls(len(test_cases),test_cases))
                
            
