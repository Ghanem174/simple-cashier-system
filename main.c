
// Libraries
#include <errno.h>  //to save check in text file
#include <stdio.h>  //Main Library
#include <stdlib.h> //Main Library

// Most of the functions are made with do while loop because it doesn't exit
// until the user wants

// Functions
void print_menu();    // displays options of the menu
void list_products(); // displays the available product
void add_item();      // function to add products to cart
void display_cart();  // display whats inside the cart
void delete_item();   // remove item from the cart
void check_out();     // checkout bill that ends the program
void total_selling(); // display's total bill currently
void inventory();     // Displays the Remaining inventory

// Typedef structure for the list of products which contain: name, price,
// quantity, and code.
typedef struct {
  char name[30]; // name of product
  float price;   // price of product
  int quantity;  // available quantity of product
  int code;      // the code of product
} product;

// typedef structure for the inventory of products
typedef struct {
  float price;  // total price in cart
  int quantity; // total quantity in cart
  int code;     // code of product
} cart;

// Declarations for the products
product product1 = {"Water", 3.5, 10, 1};
product product2 = {"Coffee", 5.25, 10, 2};
product product3 = {"Sandwich", 6.75, 10, 3};
product product4 = {"Chicken Meal", 8.5, 10, 4};
product product5 = {"Beef Meal", 9.0, 10, 5};

// declarations for the cart
cart c1; // cart for water
cart c2; // cart for coffee
cart c3; // cart for  sandwich
cart c4; // cart for chicken meal
cart c5; // cart for beef meal

// main program
int main(void) {
  int menu_option; // user desired option in menu

  do {
    print_menu(); // displays the menu

    printf("Enter Desired Option: "); // pick an operation for the menu
    scanf("%d", &menu_option);

    // if statement to perform the desired operation
    if (menu_option == 1) {
      list_products(); // show the menu of the products
    } else if (menu_option == 2) {
      add_item(); // add products to the cart
    } else if (menu_option == 3) {
      display_cart(); // show the items in cart
    } else if (menu_option == 4) {
      delete_item(); // remove items from cart
    } else if (menu_option == 5) {
      checkout(); // prints receipt and ends the program
      break;      // ends the whole program
    } else if (menu_option == 6) {
      total_selling(); // show total amount in cart
    } else if (menu_option == 7) {
      inventory(); // shows the available inventory of products
    }

  } while (menu_option !=
           0); // while the user didn't enter zero the program is working

  return 0;
}

// prints program Main Menu
void print_menu() {
  printf("\n\t\t El-Alamein Cafeteria\n");
  printf("---------------------------------------------------------\n");
  printf("1- List All Products\n");
  printf("2- Add Items to Cart\n");
  printf("3- Display Items In Cart\n");
  printf("4- Delete Item from Cart\n");
  printf("5- Check Out\n");
  printf("6- Total Selling Value\n");
  printf("7- Inventory\n");
  printf("0- Exit\n\n");
}

// prints food menu
void list_products() {
  int back; // to return to the menu

  do {
    printf("\n\t\t\tFood Menu\n"); // title
    printf("--------------------------------------------------------------\n");
    printf("Product \t\t Price \t\t Quantity\t Code\n\n");
    printf("%s\t\t\t",
           product1.name); // prints name from the structured array of products
    printf("%.2f$\t\t", product1.price); // prints the price from the structured
                                         // array of products
    printf("%d\t\t",
           product1.quantity);     // checks the available quantity of product
    printf("%d\n", product1.code); // the code of product

    printf("%s\t\t\t",
           product2.name); // prints from the structured array of products
    printf("%.2f$\t\t", product2.price); // prints the price from the structured
                                         // array of products
    printf("%d\t\t",
           product2.quantity);     // checks the available quantity of product
    printf("%d\n", product2.code); // the code of product

    printf("%s\t\t",
           product3.name); // prints from the structured array of products
    printf("%.2f$\t\t", product3.price); // prints the price from the structured
                                         // array of products
    printf("%d\t\t",
           product3.quantity);     // checks the available quantity of product
    printf("%d\n", product3.code); // the code of product

    printf("%s\t\t",
           product4.name); // prints from the structured array of products
    printf("%.2f$\t\t", product4.price); // prints the price from the structured
                                         // array of products
    printf("%d\t\t",
           product4.quantity);     // checks the available quantity of product
    printf("%d\n", product4.code); // the code of product

    printf("%s\t\t",
           product5.name); // prints from the structured array of products
    printf("%.2f$\t\t", product5.price); // prints the price from the structured
                                         // array of products
    printf("%d\t\t",
           product5.quantity);       // checks the available quantity of product
    printf("%d\n\n", product5.code); // the code of product

    printf(
        "Press 0 to go back to the menu: "); // user presses 0 to exit the menu
    scanf("%d", &back);

  } while (back != 0);
}

// function to add items to cart
void add_item() {

  int c = 0, quantity = 0; // c = code to return to main menu

  printf("\n\t\t Add items to Cart\n"); // title
  printf("---------------------------------------------------------\n");

  printf("Press 0 when your done adding products to the cart\n\n"); // to exit
                                                                    // to the
                                                                    // main menu
  printf("1- Water | 2 - Coffee | 3- Sandwiches | 4- Chicken Meal | 5- Beef "
         "Meal\n\n"); // codes of products

  do {
    printf(
        "Enter the Code of the Product: "); // user chooses the the item to add
    scanf("%d", &c);

    if (c == 0) // to leave the function
    {
      break; // break from the whole function
    }

    printf(
        "Enter the Quantity of the Product: "); // chooses the desired quantity
    scanf("%d", &quantity);

    if (c == 1) {
      if (quantity >
          product1.quantity) // to check if its available in the inventory
      {
        printf("Unavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c1.code = 1;
      c1.quantity += quantity;                 // adds the quantity to the cart
      c1.price = c1.quantity * product1.price; // calculates the total price

      product1.quantity -= quantity; // removes the quantity in the inventory
      printf("\nItem Added Successfully!\n\n");

    } else if (c == 2) {
      if (quantity >
          product2.quantity) // to check if its available in the inventory
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c2.code = 2;
      c2.quantity += quantity;                 // adds the quantity to the cart
      c2.price = c2.quantity * product2.price; // calculates the total price

      product2.quantity -= quantity; // remove the quantity in the inventory
      printf("\nItem Added Successfully!\n\n");
    } else if (c == 3) {
      if (quantity >
          product3.quantity) // to check if its available in the inventory
      {
        printf("Unavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c3.code = 3;
      c3.quantity += quantity;                 // adds the quantity to the cart
      c3.price = c3.quantity * product3.price; // calculates the total price

      product3.quantity -= quantity; // remove the quantity in the inventory
      printf("\nItem Added Successfully!\n\n");
    } else if (c == 4) {
      if (quantity >
          product4.quantity) // to check if its available in the inventory
      {
        printf("Unavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c4.code = 4;
      c4.quantity += quantity;                 // adds the quantity to the cart
      c4.price = c4.quantity * product4.price; // calculates the total price

      product4.quantity -= quantity; // removes the quantity in the inventory
      printf("\nItem Added Successfully!\n\n");
    } else if (c == 5) {
      if (quantity >
          product5.quantity) // to check if its available in the inventory
      {
        printf("Unavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c5.code = 5;
      c5.quantity += quantity;                 // adds the quantity to the cart
      c5.price = c5.quantity * product5.price; // calculates the total price

      product5.quantity -= quantity; // remove the quantity in the inventory
      printf("\nItem Added Successfully!\n\n");
    } else {
      printf("This Code is Incorrect\n\n");
    }

  } while (c != 0);
}
void display_cart() {
  int exit; // exit = code 0 to return to main menu

  do {
    printf("\n\n\t\t\t Cart\n"); // title
    printf("-----------------------------------------------------\n");
    printf("Product\t\t Quantity\t Code\t Total Price\n\n");

    if (c1.quantity > 0) // if the user add this item to cart, it prints in cart
    {
      printf("Water\t\t");
      printf("%d\t\t", c1.quantity); // quantity in cart
      printf("%d\t", c1.code);       // code of product
      printf("%.2f$\n", c1.price);   // price of product
    }

    if (c2.quantity > 0) // if the user add this item to cart, it prints in cart
    {
      printf("Coffee\t\t");
      printf("%d\t\t", c2.quantity); // quantity in cart
      printf("%d\t", c2.code);       // code of product
      printf("%.2f$\n", c2.price);   // quantity in cart
    }

    if (c3.quantity > 0) // if the user add this item to cart, it prints in cart
    {
      printf("Sandwich\t");
      printf("%d\t\t", c3.quantity); // quantity in cart
      printf("%d\t", c3.code);       // code of product
      printf("%.2f$\n", c3.price);   // quantity in cart
    }

    if (c4.quantity > 0) // if the user add this item to cart, it prints in cart
    {
      printf("Chicken Meal\t");
      printf("%d\t\t", c4.quantity); // quantity in cart
      printf("%d\t", c4.code);       // code of product
      printf("%.2f$\n", c4.price);   // quantity in cart
    }

    if (c5.quantity > 0) // if the user add this item to cart, it prints in cart
    {
      printf("Beef Meal\t");
      printf("%d\t\t", c5.quantity); // quantity in cart
      printf("%d\t", c5.code);       // code of product
      printf("%.2f$\n", c5.price);   // quantity in cart
    }

    printf("\nPress 0 to return to menu: "); // to return to main menu
    scanf("%d", &exit);
  } while (exit != 0);
}
void delete_item() {
  int c = 0, quantity = 0; // c = code to exit function, quantity= quantity of
                           // items want to be removed

  printf("\n\t\t Remove items from Cart\n"); // title
  printf("-----------------------------------------------------------\n");

  printf("Press 0 when your done removing products to the cart\n\n");
  printf("1- Water | 2 - Coffee | 3- Sandwiches | 4- Chicken Meal | 5- Beef "
         "Meal\n\n");

  do {
    printf("Enter the Code of the Product: "); // code of product to be removed
    scanf("%d", &c);

    if (c == 0) // breaks from the function to return to menu
    {
      break;
    }

    printf("Enter the Quantity of the Product: "); // quantity of product that
                                                   // you want to remove
    scanf("%d", &quantity);

    if (c == 1) {
      if (quantity > c1.quantity) // check if the quantity want to be removed is
                                  // available in cart.
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c1.quantity -= quantity;              // removes the quantity from cart
      c1.price = quantity * product1.price; // recalculates the total price

      product1.quantity += quantity; // add quantity back to inventory

      printf("\nItem Removed Successfully!\n\n");

    } else if (c == 2) {
      if (quantity > c2.quantity) // check if the quantity want to be removed is
                                  // available in cart.
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c2.quantity -= quantity;              // removes the quantity from cart
      c2.price = quantity * product2.price; // recalculates the total price

      product2.quantity += quantity; // add quantity back to inventory

      printf("\nItem Removed Successfully!\n\n");
    } else if (c == 3) {
      if (quantity > c3.quantity) // check if the quantity want to be removed is
                                  // available in cart.
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c3.quantity -= quantity;              // removes the quantity from cart
      c3.price = quantity * product3.price; // recalculates the total price

      product3.quantity += quantity; // add quantity back to inventory

      printf("\nItem Removed Successfully!\n\n");
    } else if (c == 4) {
      if (quantity > c4.quantity) // check if the quantity want to be removed is
                                  // available in cart.
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c4.quantity -= quantity;              // removes the quantity from cart
      c4.price = quantity * product4.price; // recalculates the total price

      product4.quantity += quantity; // add quantity back to inventory

      printf("\nItem Removed Successfully!\n\n");
    } else if (c == 5) {
      if (quantity > c5.quantity) // check if the quantity want to be removed is
                                  // available in cart.
      {
        printf("\nUnavailable Quantity, Enter Quantity Again\n\n");
        break;
      }
      c5.quantity -= quantity;              // removes the quantity from cart
      c5.price = quantity * product5.price; // recalculates the total price

      product5.quantity += quantity; // add quantity back to inventory

      printf("\nItem Removed Successfully!\n\n");
    } else {
      printf("This Code is Incorrect\n\n"); // unavailable code
    }

  } while (c != 0);
}

void checkout() {
  FILE *check = fopen("check", "w");

  float sum = 0, tax = 0,
        total = 0; // sum = to add sum of items, tax = to calculates the tax of
                   // items, total = sum + tax

  printf("\n\t\t\t Checkout\n"); // title
  printf("------------------------------------------------------\n");
  printf("Product\t\t Quantity\t Code\t Total Price\n\n");

  fprintf(check, "\n\t\t\t Checkout\n"); // prints in text file
  fprintf(
      check,
      "------------------------------------------------------\n"); // prints in
                                                                   // text file
  fprintf(
      check,
      "Product\t\t Quantity\t Code\t Total Price\n\n"); // prints in text file

  if (c1.quantity >
      0) // if the user add item to cart, it will be shown on receipt
  {
    printf("Water\t\t");
    printf("%d\t\t", c1.quantity); // quantity in cart
    printf("%d\t", c1.code);       // code of product
    printf("%.2f$\n", c1.price);   // total price of product

    fprintf(check, "Water\t\t");           // prints in text file
    fprintf(check, "%d\t\t", c1.quantity); // prints in text file
    fprintf(check, "%d\t", c1.code);       // prints in text file
    fprintf(check, "%.2f$\n", c1.price);   // prints in text file

    sum += (c1.quantity * product1.price); // adds to sum
  }

  if (c2.quantity >
      0) // if the user add item to cart, it will be shown on receipt
  {
    printf("Coffee\t\t");
    printf("%d\t\t", c2.quantity); // quantity in cart
    printf("%d\t", c2.code);       // code of product
    printf("%.2f$\n", c2.price);   // total price of product

    fprintf(check, "Coffee\t\t");          // prints in text file
    fprintf(check, "%d\t\t", c2.quantity); // prints in text file
    fprintf(check, "%d\t", c2.code);       // prints in text file
    fprintf(check, "%.2f$\n", c2.price);   // prints in text file

    sum += (c2.quantity * product2.price); // adds to sum
  }

  if (c3.quantity >
      0) // if the user add item to cart, it will be shown on receipt
  {
    printf("Sandwich\t");
    printf("%d\t\t", c3.quantity); // quantity in cart
    printf("%d\t", c3.code);       // code of product
    printf("%.2f\n", c3.price);    // total price of product

    fprintf(check, "Sandwich\t");          // prints in text file
    fprintf(check, "%d\t\t", c3.quantity); // prints in text file
    fprintf(check, "%d\t", c3.code);       // prints in text file
    fprintf(check, "%.2f\n", c3.price);    // prints in text file

    sum += (c3.quantity * product3.price); // adds to sum
  }

  if (c4.quantity >
      0) // if the user add item to cart, it will be shown on receipt
  {
    printf("Chicken Meal\t");
    printf("%d\t\t", c4.quantity); // quantity in cart
    printf("%d\t", c4.code);       // code of product
    printf("%.2f\n", c4.price);    // total price of product

    fprintf(check, "Chicken Meal\t");      // prints in text file
    fprintf(check, "%d\t\t", c4.quantity); // prints in text file
    fprintf(check, "%d\t", c4.code);       // prints in text file
    fprintf(check, "%.2f\n", c4.price);    // prints in text file

    sum += (c4.quantity * product4.price); // adds to sum
  }

  if (c5.quantity >
      0) // if the user add item to cart, it will be shown on receipt
  {
    printf("Beef Meal\t");
    printf("%d\t\t", c5.quantity); // quantity in cart
    printf("%d\t", c5.code);       // code of product
    printf("%.2f\n", c5.price);    // total price of product

    fprintf(check, "Beef Meal\t");
    fprintf(check, "%d\t\t", c5.quantity); // prints in text file
    fprintf(check, "%d\t", c5.code);       // prints in text file
    fprintf(check, "%.2f\n", c5.price);    // prints in text file

    sum += (c5.quantity * product5.price); // adds to sum
  }

  printf("\n\n");
  tax = sum * 0.14;                             // calculates tax
  total = sum + tax;                            // calculates total
  printf("Total = %.2f$\t", sum);               // prints sum of products
  printf("Tax = %.2f$\t", tax);                 // prints the tax
  printf("Total After Tax = %.2f$\t\n", total); // adds the sum and tax

  fprintf(check, "\n\n");                               // prints in text file
  fprintf(check, "Total = %.2f$\t", sum);               // prints in text file
  fprintf(check, "Tax = %.2f$\t", tax);                 // prints in text file
  fprintf(check, "Total After Tax = %.2f$\t\n", total); // prints in text file

  printf(
      "---------------------------------------------------------\n"); // End
                                                                      // Title
  printf("\t\t\tOrder Done\n\n");

  fprintf(
      check,
      "---------------------------------------------------------\n"); // End
                                                                      // Title
  fprintf(check, "\t\t\tOrder Done\n\n");

  fclose(check);
}
void total_selling() {
  float sum = 0, tax = 0, total = 0, x;

  do {
    printf("\n\t\tTotal Selling Value\n"); // title
    printf("---------------------------------------------------------\n");
    printf("Product\t\t Quantity\t Code\t Total Price\n\n");

    if (c1.quantity >
        0) // if the user add item to cart, it will be shown on receipt
    {
      printf("Water\t\t");
      printf("%d\t\t", c1.quantity); // quantity in cart
      printf("%d\t", c1.code);       // code of product
      printf("%.2f\n", c1.price);    // total price of product

      sum += (c1.quantity * product1.price);
    }

    if (c2.quantity >
        0) // if the user add item to cart, it will be shown on receipt
    {
      printf("Coffee\t\t");
      printf("%d\t\t", c2.quantity); // quantity in cart
      printf("%d\t", c2.code);       // code of product
      printf("%.2f\n", c2.price);    // total price of product

      sum += (c2.quantity * product2.price);
    }

    if (c3.quantity >
        0) // if the user add item to cart, it will be shown on receipt
    {
      printf("Sandwich\t");
      printf("%d\t\t", c3.quantity); // quantity in cart
      printf("%d\t", c3.code);       // code of product
      printf("%.2f\n", c3.price);    // total price of product

      sum += (c3.quantity * product3.price);
    }

    if (c4.quantity >
        0) // if the user add item to cart, it will be shown on receipt
    {
      printf("Chicken Meal\t");
      printf("%d\t\t", c4.quantity); // quantity in cart
      printf("%d\t", c4.code);       // code of product
      printf("%.2f\n", c4.price);    // total price of product

      sum += (c4.quantity * product4.price);
    }

    if (c5.quantity >
        0) // if the user add item to cart, it will be shown on receipt
    {
      printf("Beef Meal\t");
      printf("%d\t\t", c5.quantity); // quantity in cart
      printf("%d\t", c5.code);       // code of product
      printf("%.2f\n", c5.price);    // total price of product

      sum += (c5.quantity * product5.price);
    }

    printf("\n");
    tax = sum * 0.14;                             // calculates tax
    total = sum + tax;                            // calculates total
    printf("Total = %.2f$\t", sum);               // prints sum
    printf("Tax = %.2f$\t", tax);                 // prints tax
    printf("Total After Tax = %.2f$\t\n", total); // prints total after tax

    printf("\n Press 0 to exit from function: ");
    scanf("%d", &x);

  } while (x != 0);
}
void inventory() {
  int x; // x is 0 to return to main menu

  do {
    printf("\n\t\t\tInventory\n"); // title
    printf("-------------------------------------------------------\n");
    printf("Product\t\t Quantity\t Code\t Total Price\n\n");

    printf("Water\t\t");
    printf("%d\t\t", product1.quantity); // item 1 available quantity
    printf("%d\t", product1.code);       // item 1 code
    printf("%.2f\n", product1.price);    // item 1 price

    printf("Coffee\t\t");
    printf("%d\t\t", product2.quantity); // item 2 available quantity
    printf("%d\t", product2.code);       // item 2 code
    printf("%.2f\n", product2.price);    // item 2 price

    printf("Sandwich\t");
    printf("%d\t\t", product3.quantity); // item 3 available quantity
    printf("%d\t", product3.code);       // item 3 code
    printf("%.2f\n", product3.price);    // item 3 price

    printf("Chicken Meal\t");
    printf("%d\t\t", product4.quantity); // item 4 available quantity
    printf("%d\t", product4.code);       // item 4 code
    printf("%.2f\n", product4.price);    // item 4 price

    printf("Beef Meal\t");
    printf("%d\t\t", product5.quantity); // item 5 available quantity
    printf("%d\t", product5.code);       // item 5 code
    printf("%.2f\n", product5.price);    // item 5 price

    printf("\nPress 0 to exit from Inventory: "); // exit from inventory
    scanf("%d", &x);
  } while (x != 0);
}
