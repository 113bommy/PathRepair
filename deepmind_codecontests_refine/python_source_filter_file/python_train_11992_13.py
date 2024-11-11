def Cards():
        size = int(input())
        binary = input()
        z_num = binary.count('z')
        n_num = binary.count('n')
        return '1'*n_num + '0'*z_num



print(Cards())

