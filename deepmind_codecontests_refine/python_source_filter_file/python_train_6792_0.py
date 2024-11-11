def join_vecs(a,b):
    out = a.copy()
    for i in range(len(b)):
        out.append(b[i])
    return out

def get_vecs(point, operation):
    curr_point = point.copy()
    if operation == 'N':
        point[1] = point[1] + 1
    if operation == 'S':
        point[1] = point[1] - 1
    if operation == 'E':
        point[0] = point[0] + 1
    if operation == 'W':
        point[0] = point[0] - 1
    
    vec_1 = ''.join(list(map(lambda x: str(x),curr_point))) + ''.join(list(map(lambda x: str(x),point)))
    vec_2 = ''.join(list(map(lambda x: str(x),point))) + ''.join(list(map(lambda x: str(x),curr_point)))
    
    return vec_1, vec_2, point

def solve(operations):
    curr_point = [0,0]
    NS_vectors = []
    EW_vectors = []
    k = 0

    for operation in operations:
        vec_1, vec_2, curr_point = get_vecs(curr_point, operation)
        if (operation == 'N') | (operation == 'S'):
                NS_vectors.append(vec_1)
                NS_vectors.append(vec_2)
        if (operation == 'E') | (operation == 'W'):
                EW_vectors.append(vec_1)
                EW_vectors.append(vec_2)
                
    k += int((len(NS_vectors) - len(set(NS_vectors)))/2) + int(len(set(NS_vectors))/2)*5
    k += int((len(EW_vectors) - len(set(EW_vectors)))/2) + int(len(set(EW_vectors))/2)*5
    return str(k)
    
t = int(input())
answers = []
for i in range(t):
    operations = input()
    answers.append(solve(operations))

print("\n".join(answers))