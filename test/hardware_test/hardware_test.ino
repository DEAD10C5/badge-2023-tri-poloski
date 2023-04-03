/*!
   @file hardware_test.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


   Author : @theDevilsVoice https://twitter.com/dead10c5
   Date   : April 3, 2023
   Version: 0.2
*/

#include "dead10c5.h"

// DeadBadge deadbadge;
// SoftwareSerial Serial(RX, TX);

const int MPU = 0x68; // MPU6050 I2C address

void setup()
{
  Serial1.begin(9600);

  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#####&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#PJ7!~~~:......^!YB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BJ~^^7JYP5Y5J?!^7~.  :75G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&57!?YJJ7Y7!!~?7??7?JJ!~?!:75PB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P!YBBJ. :!Y?^:::^!?JJJY?J7.  ^5P5#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#!7B&G: .!J??J5G#&&&&&#PJ?J?^.. .!JYP&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@&#BBBB#&@@#B####&@@#^7GGJ. :J?7YPGB#&@@@@@@@&GJ7JJ~^   !YY&@@@@&BP5G#@@&#BB####@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@&P.....:.YB^..:. 5&&~7Y.~^: ~YY....::.5&@@@&#P7: YJ:.    ^J?&@&P^.  :.7BY...... G@@@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.. :.~. Y::  :^G#Y~B7.~:~ ^BY:~ :.~. G&@&~:~?~ 5^. .!.. ??P&B.. .~.^ !!.  !!7Y#@@@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.~ !^^: Y::  5B#5.7G^:  . .GY:J ~^^^ 55555Y^!! Y.: .Y.7 !Y:JY.. :J : ^~.  ..::G&@@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.! !:^. Y::... Y:  J.: :.. YY:J ~^:. Y. .B#J~! Y.: .Y:? ~~  7.: :P777Y!.  ~.: :#@@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.! !::. Y::  :^5?.7J.: ~.. 7Y:J ~^:. 5J?Y&&J~! Y:: .Y:? ~Y~!Y.: :G555P5JYYG^: .B&@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.~ !^:  Y::  G##Y~B?.   .  ^J:? ~^.  P&&@@&J~! Y.^ :Y.? ~BPPP.: :Y.^ ~~:..P^^ .B&@@@@@@@")
  Serial1.println("@@@@@@@@@@&5.. :..  Y::..!^7~.::   : ...?:? :.   5!:~##?^~ 5^. .!.: !7..Y.:..~.  77.: !:. :#@@@@@@@@")
  Serial1.println("@@@@@@@@@@&P..... .?G^.::: ^~ ..   Y!...7.:... .7G^ .B&J...GG~.     ^~  55:.   .7B#7.. . :G&@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@&#####&@@&######Y!BG5  YB#####BGP5PGGG55PBBBGB#&&&J:55J  J55&&&BGGB&@@@@&BGG#&@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@5?&&G  Y#&#BGPP55YJY?^7?7!?7?JYPGBY^##Y  ?GG@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@5?&&G .JPGGY5P?J5:.J~^?Y?.!  ~:.?YJ75P?  ?GG@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@P?&BPYG#&&G!?J557!!J???!^.. .7~J5PPGP5Y~ JGG@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@PJPB&@@@@@BG&#BGPPPJ.   .^^7JY5PPPPPGGGG5?JP&@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@&GP#@@@@@@&#BPYJ7!~^.     .^~!7?JYYY5PPGGGGPY7Y#@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@#P#@@@@@&#PYJ?77?J7Y5?PGPPBG55Y??77777!?55PGGGP~:5&@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@GP&@@@@&GYJ???JY?#&#&@@@@@@@&@@@&&#P5J!^:^~?YPBBBJ.7&@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@&5G@@@@&P?~~~JYYB&&@@@&&@@@@@BYP&@@@@@@&G5~..:~?YB&&B:!&@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@&YP@@@&G?~  !J?G&@@@&#5~B@@@@@@&JB@@@@@@@@@#P!..:!YP&&#~7&@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@G?&@@&?^: :?G&@@@@&PJ!!5YG&@@@#G&@@@@@@@@@@@@&5:.:^?J#&&7P@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@&~B&@#~:. ^5BB@@@@@@#&&&#?^?&&G!JB@@@@@@@@@@@@&&G^..:~!#&&5&@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@&P~&&&!:. ^GGGB@@&&&&&&#G5!!.G#~~^JPB#&&&&&@@@@#GBG^  .:7B&#G@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@&?J&&Y.:..5JG&@&&#BBGPP5YJJ!:G#7^?JJY5PGGBB&&@@&YYG5.  ::!G#P@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@&!G&#^:..!7B&&5^!5555YY555PY^5#J!G555YJ5555J~7B&#JPG?  .:~~B5&@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@&JGBP.:..55JBY.7J55555555Y55:YB?75YYY555555Y?^:BB7GG5 ..~7^YY&@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@&5YGY^!^.PG77:~5YP5555555557.G#Y^YPPPP555555J5.77^PG5 :.!~PYP@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@B!P5J?^.5GJ? :!Y555555P55J: 7Y7.!YPPPP55555J!..!!#BP.7:~^B?#@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@&7?GPY! !PYY   :7Y55YJ!^7^:~5GGY^!7~7Y5P5Y~.  .5!GG7.~::??J&@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@#755Y7: JJPY:77^^~~7?.  ..Y#&&#!.. :!^^~~:~~:YG?JY .:!^?~&@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@B!~~^^::PY5P5GB5755: .. .P#&&#~.   :J7^5B55PPJYP. ^?Y7:B@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@&G: :^^^:55J~!Y5Y?::7JJ~?B#&&&G^~^...!YYJ:.?5P5. ^?57!B@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@B~ .::^.~^:^7~:~7Y555YYGBB#&#?5P5J!^:    :J7..7YJ!Y#@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@&Y. ::^.:!!~^ :7J555J!!?7~!JYJ55J7^ .  :^. .^7~!G&@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@#Y::^. 7..^: .:~?~^YBB#B5~.^^^:: ^!^ :     ~5&@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y~  ~ .!. !5P~ YB#&@@@#! 7YP?..7. ^  .!G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B7  ~J.   ^5P:.?G#&@@@&5 :~J~    !J :5#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@&#BPJ!:  ..~7     ~~^JPP5YYY7.  :     ^?:.^~7YPB#&@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@#7..^.   ....^ .. : ^7J?~~~~~~:...! .. : :!!~~~~!7!??#@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@&Y ....^~!YBBGBP::    !?~^:.:~?YYPP~ . ::7BBBGPY7J?!^:~#@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@&B:.....7B&@@@&#5..   ^.  .. ^^^~.7.  . ~GB&&@&#5!.:.^^#@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@&G.   . J##GPYJ7! .^.   .^...:.    .~..7JY5PB##!.  :.P&@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@&5.   :.7!7^:. :YG#G?:   .::.  .~JGBY^  .:~JJ!.. ^:J&@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@&G:. .. .  .~5#@@@@@&#BBG5PGGB&&@@@&B?:    ^ ..~75&@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@&Y^.:.77P#@@@@@@@@@@@@@@@@@@@@@@@@@@&#G?~!.:!P&@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
  Serial1.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")

  delay(1000);
  Serial1.println("#######################################");
  Serial1.println("# взаимоблокировщики Русский хардбасс #");
  Serial1.println("#######################################");
  Serial1.println("This badge was a lot of fun to make. Hope you enjoy it!");
  Serial1.println("...");
  Serial1.print("Version: ");
  Serial1.println(VERSION);
  delay(1000);

  Serial1.println("Concept: Yaya Pancho");
  Serial1.println("Translations: @muscovitebob");
  Serial1.println("Artwork: @p0lr_")
  Serial1.println("Hardware: @p0lr_ @thedevilsvoice");
  Serial1.println("Software: @thedevilsvoice");
  delay(1000);

  pinMode(BOTTOM_ROW, OUTPUT);
  pinMode(MIDDLE_ROW, OUTPUT);
  pinMode(TOP_ROW, OUTPUT);

  Wire.begin();                // Initialize comunication
  Wire.beginTransmission(MPU); // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);            // Talk to the register 6B
  Wire.write(0x00);            // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);  // end the transmission

  /*
  // Configure Accelerometer Sensitivity - Full Scale Range (default +/- 2g)
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register (1C hex)
  Wire.write(0x10);                  //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);
  // Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                   // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  */
  // Call this function if you need to get the IMU error values for your module
  // calculate_IMU_error();
  // delay(20);
}

void loop()
{

  Serial1.println("Bottom row");
  digitalWrite(BOTTOM_ROW, HIGH);
  delay(1000);
  digitalWrite(BOTTOM_ROW, LOW);
  delay(1000);

  Serial1.println("Middle row");
  digitalWrite(MIDDLE_ROW, HIGH);
  delay(1000);
  digitalWrite(MIDDLE_ROW, LOW);
  delay(1000);

  Serial1.println("Top row");
  digitalWrite(TOP_ROW, HIGH);
  delay(1000);
  digitalWrite(TOP_ROW, LOW);
  delay(1000);

  // === Read acceleromter data === //
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  // For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
  // Calculating Roll and Pitch from the accelerometer data
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) - 0.58;      // AccErrorX ~(0.58) See the calculate_IMU_error()custom function for more details
  accAngleY = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) + 1.58; // AccErrorY ~(-1.58)
  // === Read gyroscope data === //
  previousTime = currentTime;                        // Previous time is stored before the actual time read
  currentTime = millis();                            // Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  Wire.beginTransmission(MPU);
  Wire.write(0x43); // Gyro data first register address 0x43
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);                   // Read 4 registers total, each axis value is stored in 2 registers
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0; // For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  // Correct the outputs with the calculated error values
  GyroX = GyroX + 0.56; // GyroErrorX ~(-0.56)
  GyroY = GyroY - 2;    // GyroErrorY ~(2)
  GyroZ = GyroZ + 0.79; // GyroErrorZ ~ (-0.8)
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by sendonds (s) to get the angle in degrees
  gyroAngleX = gyroAngleX + GyroX * elapsedTime; // deg/s * s = deg
  gyroAngleY = gyroAngleY + GyroY * elapsedTime;
  yaw = yaw + GyroZ * elapsedTime;
  // Complementary filter - combine acceleromter and gyro angle values
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;

  // Print the values on the serial monitor
  Serial1.print(roll);
  Serial1.print("/");
  Serial1.print(pitch);
  Serial1.print("/");
  Serial1.println(yaw);
}

void calculate_IMU_error()
{
  // We can call this funtion in the setup section to calculate the accelerometer and gyro data error. From here we will get the error values used in the above equations printed on the Serial Monitor.
  // Note that we should place the IMU flat in order to get the proper values, so that we then can the correct values
  // Read accelerometer values 200 times
  while (c < 200)
  {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    AccX = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccY = (Wire.read() << 8 | Wire.read()) / 16384.0;
    AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0;
    // Sum all readings
    AccErrorX = AccErrorX + ((atan((AccY) / sqrt(pow((AccX), 2) + pow((AccZ), 2))) * 180 / PI));
    AccErrorY = AccErrorY + ((atan(-1 * (AccX) / sqrt(pow((AccY), 2) + pow((AccZ), 2))) * 180 / PI));
    c++;
  }
  // Divide the sum by 200 to get the error value
  AccErrorX = AccErrorX / 200;
  AccErrorY = AccErrorY / 200;
  c = 0;
  // Read gyro values 200 times
  while (c < 200)
  {
    Wire.beginTransmission(MPU);
    Wire.write(0x43);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);
    GyroX = Wire.read() << 8 | Wire.read();
    GyroY = Wire.read() << 8 | Wire.read();
    GyroZ = Wire.read() << 8 | Wire.read();
    // Sum all readings
    GyroErrorX = GyroErrorX + (GyroX / 131.0);
    GyroErrorY = GyroErrorY + (GyroY / 131.0);
    GyroErrorZ = GyroErrorZ + (GyroZ / 131.0);
    c++;
  }
  // Divide the sum by 200 to get the error value
  GyroErrorX = GyroErrorX / 200;
  GyroErrorY = GyroErrorY / 200;
  GyroErrorZ = GyroErrorZ / 200;
  // Print the error values on the Serial Monitor
  Serial1.print("AccErrorX: ");
  Serial1.println(AccErrorX);
  Serial1.print("AccErrorY: ");
  Serial1.println(AccErrorY);
  Serial1.print("GyroErrorX: ");
  Serial1.println(GyroErrorX);
  Serial1.print("GyroErrorY: ");
  Serial1.println(GyroErrorY);
  Serial1.print("GyroErrorZ: ");
  Serial1.println(GyroErrorZ);
}
