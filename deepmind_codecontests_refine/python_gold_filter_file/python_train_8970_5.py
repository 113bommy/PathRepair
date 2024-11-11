
def get_ans(n, k, array):
    logging = {0:[]}
    for i in array:
        steps = 0
        temp = i
        while temp > 0:
            if temp not in logging.keys():
                logging[temp] = [steps]
            else:
                logging[temp].append(steps)
            temp = temp // 2
            steps +=1
        logging[0].append(steps)
    
    ans = sum(logging[0])
    for key, values in logging.items():
        if len(values) >= k:
            temp_ans = sum(sorted(values)[0:k])
            if temp_ans < ans:
                ans = temp_ans
        

    return ans
n, k = list(map(int, input().strip().split()))
array = list(map(int, input().strip().split()))
print(get_ans(n, k, array))