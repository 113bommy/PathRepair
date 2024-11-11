password_input = input()
password_list = []

for z in range(0, len(password_input)):
    password_list.insert(z, password_input[z])


def is_good_password(password_list):

    number_of_uppercase = 0
    number_of_lowercase = 0
    number_of_digit = 0
    number_of_speacial_character = 0


    if len(password_list) < 5:
        return "Too weak"

    for i in password_list:
        if i.isupper():
            number_of_uppercase += 1
        elif i.islower():
            number_of_lowercase += 1
        elif i in "0" "1" "2" "3" "4" "5" "6" "7" "8" "9":
            number_of_digit += 1
        elif i in "!" "?" "." "," "_":
            number_of_speacial_character += 1

    if number_of_uppercase and number_of_uppercase and number_of_digit > 1:
        return "Correct"
    else:
        return "Too weak"


print(is_good_password(password_list))
