// converter.c
}


static void menu(void) {
puts("--- Unit Converter ---");
puts("1 - Length");
puts("2 - Mass");
puts("3 - Temperature");
puts("4 - Volume");
puts("5 - Speed");
puts("0 - Exit");
}


int main(void) {
int choice;
char from[32], to[32];
double value, result;


while (1) {
menu();
if (!read_int("Enter category: ", &choice)) { puts("Invalid input"); continue; }
if (choice == 0) { puts("Goodbye."); break; }
switch (choice) {
case 1: // Length
print_length_units();
if (!read_double("Enter value: ", &value)) { puts("Invalid number"); break; }
printf("From unit: "); if (!fgets(from, sizeof(from), stdin)) break; from[strcspn(from, "\r\n")] = 0;
printf("To unit: "); if (!fgets(to, sizeof(to), stdin)) break; to[strcspn(to, "\r\n")] = 0;
result = m_to_length(to, length_to_m(from, value));
if (!isfinite(result)) { puts("Conversion failed (unsupported unit)"); break; }
printf("%.12g %s = %.12g %s\n", value, from, result, to); break;
case 2: // Mass
print_mass_units();
if (!read_double("Enter value: ", &value)) { puts("Invalid number"); break; }
printf("From unit: "); if (!fgets(from, sizeof(from), stdin)) break; from[strcspn(from, "\r\n")] = 0;
printf("To unit: "); if (!fgets(to, sizeof(to), stdin)) break; to[strcspn(to, "\r\n")] = 0;
result = kg_to_mass(to, mass_to_kg(from, value));
if (!isfinite(result)) { puts("Conversion failed (unsupported unit)"); break; }
printf("%.12g %s = %.12g %s\n", value, from, result, to); break;
case 3: // Temperature
print_temp_units();
if (!read_double("Enter value: ", &value)) { puts("Invalid number"); break; }
printf("From unit: "); if (!fgets(from, sizeof(from), stdin)) break; from[strcspn(from, "\r\n")] = 0;
printf("To unit: "); if (!fgets(to, sizeof(to), stdin)) break; to[strcspn(to, "\r\n")] = 0;
result = temp_convert(from, to, value);
if (!isfinite(result)) { puts("Conversion failed (unsupported unit)"); break; }
printf("%.12g %s = %.12g %s\n", value, from, result, to); break;
case 4: // Volume
print_vol_units();
if (!read_double("Enter value: ", &value)) { puts("Invalid number"); break; }
printf("From unit: "); if (!fgets(from, sizeof(from), stdin)) break; from[strcspn(from, "\r\n")] = 0;
printf("To unit: "); if (!fgets(to, sizeof(to), stdin)) break; to[strcspn(to, "\r\n")] = 0;
result = l_to_vol(to, vol_to_l(from, value));
if (!isfinite(result)) { puts("Conversion failed (unsupported unit)"); break; }
printf("%.12g %s = %.12g %s\n", value, from, result, to); break;
case 5: // Speed
print_speed_units();
if (!read_double("Enter value: ", &value)) { puts("Invalid number"); break; }
printf("From unit: "); if (!fgets(from, sizeof(from), stdin)) break; from[strcspn(from, "\r\n")] = 0;
printf("To unit: "); if (!fgets(to, sizeof(to), stdin)) break; to[strcspn(to, "\r\n")] = 0;
result = ms_to_speed(to, speed_to_ms(from, value));
if (!isfinite(result)) { puts("Conversion failed (unsupported unit)"); break; }
printf("%.12g %s = %.12g %s\n", value, from, result, to); break;
default:
puts("Invalid category"); break;
}
puts("");
}
return 0;
}
