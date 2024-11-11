def get_not_elements(a:list):
    elements = set(a)
    max_element = a[-1] +2 
    not_elements = []
    for i in range(0,max_element):
        if not i in elements:
            not_elements.append(i)
    not_elements.reverse()
    return not_elements

#Ahora pensar esta funcion...
def is_valid(a : list):

    for i in range(len(a)):
        if a[i]-1 > i:
            return False
    return True

def generate_array(a : list):
    
    stack_ = get_not_elements(a)
    b = [-1 for i in range(len(a))]
    val = a[0]
    for i in range(1,len(a)):
        if a[i] != val:
            b[i] = val
            val = a[i]

    if len(stack_)>0:
        val = stack_.pop()
    else:
        val = a[0]

    for i in range(len(a)):
        if b[i] == -1:
            b[i] = val

            if len(stack_)>0:
                val = stack_.pop()
    return b 


if __name__ == "__main__":
    size  =int(input())
    array = [int(i) for i in input().split()]


    if not is_valid(array):
        print(-1)
    else:
        b = generate_array(array)
        b = " ".join([str(i) for i in b])
        print(b)
    