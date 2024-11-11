def decimal_to_binary(number, n):
    bin_representation_to_str = str(bin(number)[2:])
    if len(bin_representation_to_str) != n:
        new_representation = ""
        for i in range(abs(n-len(bin_representation_to_str))):
            new_representation+="0"
        
        return [1 if i == '1' else -1 for i in new_representation + bin_representation_to_str]
    else:
        return [1 if i == '1' else -1 for i in bin_representation_to_str]

def dot_product(v1, v2):
    dot_product = 0
    for i, j in zip(v1, v2):
        dot_product += i*j
    return dot_product

if __name__ == "__main__":
    n = int(input())
    angles = [int(input()) for _ in range(n)]
    flag = False
    for i in range(2**n):
        if dot_product(decimal_to_binary(i, n), angles) == 0 or  (dot_product(decimal_to_binary(i, n), angles))%360 == 0:
            print("YES")
            flag = True
            break
    if not flag:
        print("NO")
