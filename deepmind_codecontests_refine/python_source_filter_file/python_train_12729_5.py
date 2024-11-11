def unique(x):
    upper_ret = []
    lower_ret = []
    for _, i in enumerate(x):
        if i not in upper_ret and i.isupper(): 
            upper_ret.append(i)
        elif i not in lower_ret and i.islower():
            lower_ret.append(i)
    return sorted(upper_ret), sorted(lower_ret)

def count(x):
    x = list(x)
    x_unique, _ = unique(x)
    counter = [0]*len(x_unique)
    for i in range(len(x_unique)):
        counter[i] = x.count(x_unique[i])
    return x_unique, counter


#==============================================#
owner = str(input()).strip().upper()
guest = str(input()).strip().upper()
combination = str(input()).strip().upper()

def checkMatch(owner, guest, combination):
    upper_ret_1, counter_1 = count(owner + guest)
    upper_ret_2, counter_2 = count(combination)

    if len(upper_ret_1) != len(upper_ret_1):
        return "NO"

    for a, b in zip(upper_ret_1, upper_ret_2):
        if a != b:
            return "NO"
    
    for a, b in zip(counter_1, counter_2):
        if a != b:
            return "NO"
    else:
        return "YES"

print(checkMatch(owner, guest, combination))