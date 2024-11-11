n = int(input())

def main(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    answer = 1

    for i in range(n - 1):
        answer = (answer * 3) % 1000003

    return answer

print(main(n))
    
