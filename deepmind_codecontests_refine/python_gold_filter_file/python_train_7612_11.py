from math import floor

if __name__ == '__main__':
    n_l_r = [int(i) for i in input().split()]
    arr = []
    module = 10 ** 9 + 7
    for i in range(3):
        arr.append(floor((n_l_r[2] - i) / 3) - floor((n_l_r[1] - i - 1) / 3))
    a = arr[0]
    b = arr[1]
    c = arr[2]
    for _ in range(1, n_l_r[0]):
        aux_arr1 = (a * arr[0] + b * arr[2] + c * arr[1]) % module
        aux_arr2 = (a * arr[1] + b * arr[0] + c * arr[2]) % module
        aux_arr3 = (a * arr[2] + b * arr[1] + c * arr[0]) % module
        a = aux_arr1
        b = aux_arr2
        c = aux_arr3
    print(a)
	 	 	 			 							   			  	 	