### Основи на JavaScript

#### Въведение в JavaScript

- **Какво е JavaScript и неговото място в уеб разработката**

  JavaScript е скриптов език за програмиране, който се използва за добавяне на интерактивност и динамично съдържание към уеб страници. Той е една от трите основни технологии заедно с HTML и CSS, които формират основата на уеб разработката.

- **Начини за интеграция на JavaScript в HTML**

  - **Вътрешно (Inline Script):**

    Можете да вмъкнете JavaScript код директно в HTML документа, използвайки `<script>` тагове.

    ```html
    <script>
      alert('Hello, World!');
    </script>
    ```

  - **Външно (External Script):**

    Създавате външен `.js` файл и го включвате в HTML документа.

    ```html
    <script src="script.js"></script>
    ```

  - **Inline атрибути:**

    Използване на JavaScript директно в HTML тагове чрез събитийни атрибути.

    ```html
    <button onclick="alert('Button clicked!')">Click Me</button>
    ```

#### Променливи и типове данни

- **`var`, `let`, и `const`**

  - **`var`:** Декларира променлива с функционален или глобален обхват.

    ```javascript
    var x = 10;
    ```

  - **`let`:** Декларира променлива с блоков обхват. Препоръчително за използване в съвременния JavaScript.

    ```javascript
    let y = 20;
    ```

  - **`const`:** Декларира константа с блоков обхват, чиято стойност не може да бъде променяна след инициализация.

    ```javascript
    const PI = 3.14;
    ```

- **Основни типове данни**

  - **Числа (Number):**

    ```javascript
    let age = 25;
    ```

  - **Низове (String):**

    ```javascript
    let name = 'Иван';
    ```

  - **Булеви стойности (Boolean):**

    ```javascript
    let isStudent = true;
    ```

  - **`null` и `undefined`:**

    ```javascript
    let emptyValue = null; // Умишлено празна стойност
    let notAssigned;       // undefined, защото не е присвоена стойност
    ```

  - **Обекти (Object):**

    ```javascript
    let person = { firstName: 'Мария', lastName: 'Иванова' };
    ```

  - **Масиви (Array):**

    ```javascript
    let colors = ['червен', 'зелен', 'син'];
    ```

- **Преобразуване на типове данни**

  - **Явно преобразуване:**

    ```javascript
    let num = Number('123');  // Преобразува в число 123
    let str = String(123);    // Преобразува в низ '123'
    ```

  - **Неявно преобразуване:**

    ```javascript
    let result = '5' * 2; // Резултатът е 10 (число)
    ```

---

### Оператори

- **Математически оператори**

  - **Събиране (+), Изваждане (-), Умножение (*), Деление (/), Остатък (%):**

    ```javascript
    let a = 10;
    let b = 3;
    console.log(a + b); // 13
    console.log(a - b); // 7
    console.log(a * b); // 30
    console.log(a / b); // 3.333...
    console.log(a % b); // 1
    ```

- **Оператори за сравнение**

  - **Равно (==), Тъждествено равно (===), Не е равно (!=), Тъждествено не е равно (!==):**

    - **Равно (==)**: Нарича се „сравнение по стойност“ или „нестрого сравнение“. Този оператор проверява дали двете стойности са равни по стойност, **независимо от техния тип**. Ако стойностите са от различни типове, JavaScript автоматично ще преобразува един от тях, така че да могат да се сравнят. Това преобразуване може понякога да доведе до неочаквани резултати.

    - **Тъждествено равно (===)**: Нарича се „сравнение по стойност и тип“ или „строго сравнение“. Този оператор проверява както стойността, така и типа на променливите. Ако стойностите са от различни типове, резултатът винаги ще бъде `false`, без преобразуване на типа. Това прави `===` по-надежден за случаи, когато искате да сте сигурни, че стойностите не само са равни, но и от един и същ тип.

    - Примери:

      ```javascript
      console.log(5 == '5');   
      // true (равни по стойност, защото '5' се преобразува в число)
      console.log(5 === '5');     
      // false (различни по тип: 5 е число, а '5' е низ)
      console.log(true == 1);     
      // true (true се преобразува в 1)
      console.log(true === 1);    
      // false (различни по тип: true е булева стойност, а 1 е число)
      console.log(null == undefined);     
      // true (null и undefined се считат за „равни“ при == сравнение)
      console.log(null === undefined);    
      // false (различни по тип)
      console.log(0 == false);    
      // true (0 се преобразува във false)
      console.log(0 === false);    
      // false (различни по тип: 0 е число, а false е булева стойност)
      ```

    - **Защо да използваме `===` вместо `==`**: Когато използвате `==`, JavaScript извършва така нареченото „принудително преобразуване на типа“, което може да доведе до объркващи резултати. Използването на `===` е по-добра практика, тъй като избягва автоматичното преобразуване на типовете и гарантира, че сравнявате стойности от един и същ тип. Това помага да се избегнат грешки и прави кода по-лесен за разбиране и поддръжка.


  - **По-голямо (>), По-малко (<), По-голямо или равно (>=), По-малко или равно (<=):**

    ```javascript
    console.log(10 > 5);   // true
    console.log(10 <= 10); // true
    ```

- **Логически оператори**

  - **И (&&):** Връща true, ако и двата операнда са true.

    ```javascript
    console.log(true && false); // false
    ```

  - **Или (||):** Връща true, ако поне един от операндите е true.

    ```javascript
    console.log(true || false); // true
    ```

  - **Не (!):** Обръща булевата стойност.

    ```javascript
    console.log(!true); // false
    ```

- **Оператори за присвояване**

  - **Присвояване (=), Добавяне и присвояване (+=), Изваждане и присвояване (-=), и т.н.:**

    ```javascript
    let x = 5;
    x += 3; // x = x + 3; x става 8
    x -= 2; // x = x - 2; x става 6
    ```

---

### Управление на потока

- **Условни оператори**

  - **`if`, `else if`, `else`:**

    ```javascript
    let temperature = 30;

    if (temperature > 35) {
      console.log('Много горещо');
    } else if (temperature > 25) {
      console.log('Топло');
    } else {
      console.log('Хладно');
    }
    ```

  - **`switch` оператор:**

    ```javascript
    let grade = 'B';

    switch (grade) {
      case 'A':
        console.log('Отличен');
        break;
      case 'B':
        console.log('Много добър');
        break;
      case 'C':
        console.log('Добър');
        break;
      default:
        console.log('Неизвестна оценка');
    }
    ```

- **Цикли**

  - **`for` цикъл:**

    ```javascript
    for (let i = 1; i <= 5; i++) {
      console.log('Стъпка ' + i);
    }
    ```

  - **`while` цикъл:**

    ```javascript
    let count = 1;
    while (count <= 5) {
      console.log('Брой: ' + count);
      count++;
    }
    ```

  - **`do...while` цикъл:**

    ```javascript
    let num = 1;
    do {
      console.log('Число: ' + num);
      num++;
    } while (num <= 5);
    ```

  - **`break` и `continue`:**

    ```javascript
    for (let i = 1; i <= 10; i++) {
      if (i === 5) {
        continue; // Пропуска числото 5
      }
      if (i === 8) {
        break; // Прекъсва цикъла при 8
      }
      console.log(i);
    }
    ```

---

### Функции

- **Деклариране на функции и извикване на функции**

  ```javascript
  function sayHello() {
    console.log('Здравей!');
  }

  sayHello(); // Извикване на функцията
  ```

- **Параметри и аргументи**

  ```javascript
  function greet(name) {
    console.log('Здравей, ' + name + '!');
  }

  greet('Петър'); // 'Здравей, Петър!'
  ```

- **Връщане на стойност с `return`**

  ```javascript
  function multiply(a, b) {
    return a * b;
  }

  let result = multiply(4, 5); // result е 20
  ```

- **Обхват на променливите (scope)**

  - **Глобален обхват:** Променливи, декларирани извън функции или блокове.

  - **Локален обхват:** Променливи, декларирани в рамките на функция или блок.

    ```javascript
    let globalVar = 'Глобална';

    function testScope() {
      let localVar = 'Локална';
      console.log(globalVar); // Достъпна
      console.log(localVar);  // Достъпна
    }

    testScope();
    console.log(localVar); // Грешка: localVar не е дефинирана в глобалния обхват
    ```

- **Arrow функции (`=>`)**

  ```javascript
  const add = (a, b) => a + b;

  console.log(add(2, 3)); // 5
  ```

---

### Масиви и обекти

- **Деклариране и основни операции с масиви**

  ```javascript
  let animals = ['котка', 'куче', 'зайче'];
  console.log(animals[1]); // 'куче'
  ```

- **Основни методи на масиви**

  - **`push` и `pop`:** Добавяне и премахване на елементи от края на масива.

    ```javascript
    animals.push('птица'); // Добавя 'птица'
    animals.pop();         // Премахва последния елемент
    ```

  - **`shift` и `unshift`:** Добавяне и премахване на елементи от началото на масива.

    ```javascript
    animals.unshift('слон'); // Добавя 'слон' в началото
    animals.shift();         // Премахва първия елемент
    ```

  - **`map`:** Създава нов масив чрез прилагане на функция върху всеки елемент.

    ```javascript
    let numbers = [1, 2, 3];
    let squares = numbers.map(num => num * num); // [1, 4, 9]
    ```

  - **`filter`:** Създава нов масив с елементи, които отговарят на условието.

    ```javascript
    let evenNumbers = numbers.filter(num => num % 2 === 0); // [2]
    ```

  - **`reduce`:** Агрегира стойностите на масива в една стойност.

    ```javascript
    let total = numbers.reduce((sum, num) => sum + num, 0); // 6
    ```

- **Обекти – създаване и достъп до свойства и методи**

  ```javascript
  let car = {
    make: 'BMW',
    model: 'X5',
    year: 2020,
    getInfo: function() {
      return `${this.make} ${this.model} (${this.year})`;
    }
  };

  console.log(car.getInfo()); // 'BMW X5 (2020)'
  ```

---

### DOM манипулация

- **Достъп до DOM елементи**

  - **`getElementById`:**

    ```javascript
    let header = document.getElementById('main-header');
    ```

  - **`querySelector` и `querySelectorAll`:**

    ```javascript
    let firstItem = document.querySelector('.item');
    let allItems = document.querySelectorAll('.item');
    ```

- **Промяна на съдържание и стил на елементите**

  ```javascript
  header.textContent = 'Нов заглавие';
  header.style.backgroundColor = '#f0f0f0';
  ```

- **Добавяне и премахване на елементи в DOM**

  ```javascript
  let newItem = document.createElement('li');
  newItem.textContent = 'Нов елемент';
  let list = document.getElementById('item-list');
  list.appendChild(newItem);
  ```

- **Събития и слушатели на събития (event listeners)**

  ```javascript
  let button = document.getElementById('myButton');
  button.addEventListener('click', function() {
    alert('Бутонът беше натиснат!');
  });
  ```

---

### Разширени функции и концепции

- **Callback функции и асинхронност**

  Callback функциите се използват за обработка на резултатите от асинхронни операции. Те представляват функции, които се предават като аргумент на друга функция и се извикват след приключване на асинхронна задача. Асинхронността е важна в JavaScript, тъй като позволява изпълнение на операции (например заявки към сървър), без да се блокира главния поток на изпълнение, което осигурява по-добра производителност и по-бърза реакция на интерфейса.

  - **Как работят callback функциите:** Когато извикваме функция, която приема callback, основната операция (напр. извличане на данни) се стартира, но JavaScript не изчаква тя да завърши. Вместо това, когато операцията приключи, callback функцията се извиква с резултата от операцията.

  - **Проблеми с callback функциите:** Ако има много асинхронни операции, вложени една в друга, може да се получи така нареченият "callback hell" — кодът става труден за четене и поддръжка.

  - Пример:

    В примера по-долу `fetchData` е функция, която симулира извличане на данни след закъснение (2 секунди), използвайки `setTimeout`. Когато данните са готови, callback функцията се извиква и получава тези данни като аргумент.

    ```javascript
    function fetchData(callback) {
      setTimeout(function() {
        let data = { name: 'Иван', age: 30 };
        callback(data);
      }, 2000);
    }

    fetchData(function(data) {
      console.log(data); // { name: 'Иван', age: 30 }
    });
    ```

  - **Преимущества на callback функциите:**
    - Позволяват по-голяма гъвкавост при управление на асинхронни задачи.
    - Могат да бъдат предадени различни callback функции за обработка на резултати от различни операции.

  - **Недостатъци на callback функциите:**
    - Callback функции могат да доведат до сложен и труден за четене код, особено при вложени асинхронни задачи (callback hell).
    - Трудно се обработват грешки и могат да се пропуснат грешки, ако callback функцията не ги прихване правилно.

  За да избегнем "callback hell" и да улесним управлението на асинхронния код, JavaScript предоставя други конструкции като `Promise` и `async/await`, които правят кода по-четим и по-лесен за поддръжка.


- **`Promise` и обработка на асинхронни операции**

  ```javascript
  let promise = new Promise(function(resolve, reject) {
    let success = true;
    if (success) {
      resolve('Операцията беше успешна');
    } else {
      reject('Операцията се провали');
    }
  });

  promise
    .then(function(message) {
      console.log(message);
    })
    .catch(function(error) {
      console.error(error);
    });
  ```

- **`async` и `await`**

  Позволяват по-лесно управление на асинхронен код.

  ```javascript
  async function getUserData() {
    try {
      let response = await fetch('https://api.example.com/user');
      let user = await response.json();
      console.log(user);
    } catch (error) {
      console.error('Грешка:', error);
    }
  }

  getUserData();
  ```

- **Fetch API за работа със сървъра**

  ```javascript
  fetch('https://api.example.com/data')
    .then(response => response.json())
    .then(data => {
      console.log(data);
    })
    .catch(error => {
      console.error('Грешка:', error);
    });
  ```

---

### Обработка на грешки

- **`try`, `catch`, `finally`**

  ```javascript
  try {
    // Код, който може да предизвика грешка
    let result = someUndefinedFunction();
  } catch (error) {
    console.error('Хваната грешка:', error);
  } finally {
    console.log('Това винаги се изпълнява, независимо дали има грешка');
  }
  ```

- **Обработка на грешки с `throw`**

  ```javascript
  function divide(a, b) {
    if (b === 0) {
      throw new Error('Деление на нула не е позволено');
    }
    return a / b;
  }

  try {
    let result = divide(10, 0);
    console.log(result);
  } catch (error) {
    console.error(error.message);
  }
  ```

---

### Модули в JavaScript

- **Импорт и експорт на модули**

  - **Експорт на функции или променливи:**

    ```javascript
    // В файл math.js
    export function add(a, b) {
      return a + b;
    }

    export const PI = 3.14;
    ```

  - **Импорт на функции или променливи:**

    ```javascript
    // В друг файл
    import { add, PI } from './math.js';

    console.log(add(5, 3)); // 8
    console.log(PI);        // 3.14
    ```

- **Основни концепции за модулност**

  Модулността позволява разделяне на кода на отделни файлове и повторно използване на код, което подобрява организацията и поддръжката на проекти.

---

### Допълнителни концепции

- **`this` контекст**

  `this` се отнася до текущия обект в даден контекст. Стойността на `this` може да се различава в зависимост от начина, по който функцията е извикана.

  ```javascript
  let user = {
    name: 'Анна',
    greet: function() {
      console.log('Здравей, ' + this.name);
    }
  };

  user.greet(); // 'Здравей, Анна'
  ```

- **Closures (затваряне)**

  Функция, която запазва достъп до променливите от своята външна функция, дори след като външната функция е приключила изпълнението си.

  ```javascript
  function counter() {
    let count = 0;
    return function() {
      count++;
      return count;
    };
  }

  let increment = counter();
  console.log(increment()); // 1
  console.log(increment()); // 2
  ```

- **Higher-order функции (функции от по-висок ред)**

  Функции, които приемат други функции като параметри или връщат функции като резултат.

  ```javascript
  function applyOperation(a, b, operation) {
    return operation(a, b);
  }

  let sum = applyOperation(5, 3, function(x, y) {
    return x + y;
  });

  console.log(sum); // 8
  ```

- **Прототипи и наследяване**

  JavaScript използва прототипно наследяване, където обектите могат да наследяват свойства и методи от други обекти чрез тяхната `prototype` верига.

  ```javascript
  function Animal(name) {
    this.name = name;
  }

  Animal.prototype.speak = function() {
    console.log(this.name + ' издава звук.');
  };

  let dog = new Animal('Куче');
  dog.speak(); // 'Куче издава звук.'
  ```

- **ES6+ (съвременни концепции)**

  - **Destructuring (Деструктуриране):**

    ```javascript
    let person = { firstName: 'Иван', lastName: 'Петров' };
    let { firstName, lastName } = person;
    console.log(firstName); // 'Иван'

    let [a, b] = [1, 2];
    console.log(a); // 1
    ```

  - **Spread оператор:**

    ```javascript
    let arr1 = [1, 2];
    let arr2 = [...arr1, 3, 4]; // [1, 2, 3, 4]

    let obj1 = { x: 1, y: 2 };
    let obj2 = { ...obj1, z: 3 }; // { x: 1, y: 2, z: 3 }
    ```

  - **Шаблонни низове (Template literals):**

    ```javascript
    let name = 'Петър';
    let greeting = `Здравей, ${name}!`;
    console.log(greeting); // 'Здравей, Петър!'
    ```

---

### Финални стъпки

- **Практическо приложение**

  Изградете малък проект, като например "ToDo List" приложение:

  - **Функционалности:**

    - Добавяне на нови задачи
    - Отбелязване на задачи като завършени
    - Премахване на задачи
    - Запазване на задачите в локалното съхранение на браузъра

  - **Технологии:**

    - Манипулация на DOM за създаване и обновяване на елементи
    - Събития и слушатели на събития за интеракция с потребителя
    - Използване на масиви и обекти за съхранение на данни

- **Оптимизация на код и добри практики**

  - **Писане на чист и четим код:**

    - Използване на ясни и описателни имена на променливи и функции
    - Разделяне на кода на малки, преизползваеми функции

  - **Избягване на глобални променливи:**

    - Използване на локални променливи и модулност за ограничаване на обхвата

  - **Коментари и документация:**

    - Добавяне на коментари за обяснение на сложни части от кода
    - Поддържане на актуална документация

  - **Тестване и дебъгване:**

    - Използване на инструменти за дебъгване на браузъра
    - Писане на тестове за проверка на функционалността

---