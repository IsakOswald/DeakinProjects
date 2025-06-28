# printing to the console
print("Hello")
print(one)  # we can print just with the 'print' method
print(4)
# creating variables
my_num = 25  # Note that no type has to declared first
name = "ben"  # Strings with single or double quotes
my_var = my_num  # We can set variables to others just like every other language
result = 26.1  # Doubles
am_hungry = True  # Note that 'true' is not a boolean value, its True

people = {1: "mike", 2: "John"}

names = [
    name,
    "john",
]  # Lists in python are like arrays

friends_name = names[1]  # Lists have a index like c++

# if statements and user input and type casting

user_input = input("What is your age")
user_input = int(user_input)

if user_input > 18:
    print("You can come into my store!")
else:
    print("You are under-age")

# while loops
x = 5
while x < 5:
    print(x)
    x += 1  # No increment operator

# for loops
for i in range(0, 5):  # We can use range and also the length of here donoted by ( len )
    print(i)


# functions
def get_age():  # No curly braces, just one : to then write indented
    int(input("What is your age"))  # We can string methods


# iterations

names = [
    "ben",
    "tom",
    "jerry",
    "lashi",
    "josh",
    "brianna",
    "isak",
    1,
]  # lists done have to be just one type like an array does in python

for i in names:  # We can simply do this, we dont NEED to specify the length
    print(i)

for name in range(
    len(names)
):  # we can also use then len to specify the length if needed
    print(i)

# more on dictionaries
bijective_function = {1: "a", 2: "b", 3: "c", 4: "d"}

for i in bijective_function.keys:  # We can specify that we want to output the keys
    print(i)

for (
    i
) in bijective_function.values:  # We can specify we want the output to be the values
    print(i)
