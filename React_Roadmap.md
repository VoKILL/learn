**Въведение в React**

* **Какво е React и как работи**
  * **Описание:** React е JavaScript библиотека, създадена от Facebook за изграждане на интерактивни потребителски интерфейси. Тя използва концепцията за компоненти, което позволява повторно използване на кода и по-лесно управление на сложни приложения.
  * **Пример:** С React можете да създадете компонент за бутон, който може да се използва на различни места в приложението с различни свойства.

---

**Създаване на React приложение**

* **Инсталиране на Node.js и npm**
  * **Описание:** Node.js е среда за изпълнение на JavaScript извън браузъра, а npm е пакетен мениджър, който идва с Node.js и позволява инсталирането на допълнителни библиотеки.
  * **Пример:**
    1. Изтеглете и инсталирайте Node.js от [официалния сайт](https://nodejs.org/).
    2. Проверете инсталацията в терминала:
       ```
       node -v
       npm -v
       ```

* **Използване на create-react-app за стартиране на нов проект**
  * **Описание:** create-react-app е официален инструмент, който автоматизира създаването на ново React приложение с минимална конфигурация.
  * **Пример:**
    ```
    npx create-react-app my-app
    cd my-app
    npm start
    ```
    Това ще стартира локален сървър и ще отвори приложението на `http://localhost:3000`.

---

**JSX и Render метод**

* **Какво е JSX**
  * **Описание:** JSX е разширение на JavaScript синтаксиса, което позволява писането на HTML-подобен код в JavaScript файлове. Това прави кода по-четим и лесен за разбиране.
  * **Пример:**
    ```jsx
    const element = <h1>Здравей, свят!</h1>;
    ```
    Това се компилира до:
    ```jsx
    const element = React.createElement('h1', null, 'Здравей, свят!');
    ```

* **Разбиране на render метода**
  * **Описание:** Методът `render()` определя какво ще се визуализира на екрана от даден компонент.
  * **Пример:**
    ```jsx
    class Welcome extends React.Component {
      render() {
        return <h1>Здравей, {this.props.name}</h1>;
      }
    }
    ```

---

**Компоненти**

* **Функционални и класови компоненти**
  * **Описание:** Компонентите са градивните блокове на React приложенията. Функционалните компоненти са по-прости и се използват за представяне, докато класовите компоненти могат да имат състояние и методи на жизнения цикъл.
  * **Пример за функционален компонент:**
    ```jsx
    function Greeting(props) {
      return <h1>Здравей, {props.name}</h1>;
    }
    ```
  * **Пример за класов компонент:**
    ```jsx
    class Greeting extends React.Component {
      render() {
        return <h1>Здравей, {this.props.name}</h1>;
      }
    }
    ```

* **Props и как се предават данни между компоненти**
  * **Описание:** Props (свойства) са начинът, по който данните се предават от родителски към дъщерни компоненти.
  * **Пример:**
    ```jsx
    function App() {
      return <Greeting name="Иван" />;
    }
    ```

---

**Състояние на компонента (State)**

* **Какво е state и как се използва**
  * **Описание:** State е обект, който определя текущото състояние на компонента и може да се променя през жизнения му цикъл. За разлика от `props`, който е статичен и се предава от родителския компонент, `state` се използва за управление на данни, които могат да се променят с времето в рамките на компонента. Промяната на `state` предизвиква повторно рендериране на компонента, за да се отрази новото му състояние.
  * **Пример с класов компонент:**
    ```jsx
    class Counter extends React.Component {
      constructor(props) {
        super(props);
        this.state = { count: 0 };
      }

      render() {
        return (
          <div>
            <p>Натиснати: {this.state.count} пъти</p>
            <button onClick={() => this.setState({ count: this.state.count + 1 })}>
              Натисни ме
            </button>
          </div>
        );
      }
    }
    ```
    В този пример `state` съдържа свойството `count`, което се увеличава с натискане на бутона. Методът `setState()` се използва за актуализиране на `state`, което предизвиква повторно рендериране на компонента.

* **Управление на state в компоненти**
  * **Описание:** В класовите компоненти `state` се променя с помощта на метода `setState()`. Във функционалните компоненти, от друга страна, се използва `useState()` - специален hook, който връща текущата стойност на `state` и функция за актуализация на тази стойност. Важно е да отбележим, че `setState()` и функцията за актуализация в `useState()` се извършват асинхронно.
  
  * **Пример с useState:**  
    ```jsx
    import React, { useState } from 'react';

    function Counter() {
      const [count, setCount] = useState(0);

      return (
        <div>
          <p>Натиснати: {count} пъти</p>
          <button onClick={() => setCount(count + 1)}>
            Натисни ме
          </button>
        </div>
      );
    }
    ```
    Тук използваме `useState` хук, за да създадем `count` променлива, която съхранява броя на натисканията. Функцията `setCount` служи за промяна на `count`, като всеки път, когато бутонът бъде натиснат, `count` се увеличава с 1, а компонентът се рендерира отново, за да покаже новата стойност.

  * **Пример за асинхронно актуализиране на state в класов компонент:**
    ```jsx
    class Counter extends React.Component {
      constructor(props) {
        super(props);
        this.state = { count: 0 };
      }

      increment = () => {
        this.setState((prevState) => ({ count: prevState.count + 1 }));
      }

      render() {
        return (
          <div>
            <p>Натиснати: {this.state.count} пъти</p>
            <button onClick={this.increment}>
              Натисни ме
            </button>
          </div>
        );
      }
    }
    ```
    В този пример използваме `prevState` като аргумент в `setState()`, за да се уверим, че актуализацията се извършва коректно, дори ако има множество асинхронни промени в `state`. Това е особено важно, когато актуализацията на `state` зависи от предишната стойност.

---

**Събития в React**

* **Добавяне на събития и работа с тях**
  * **Описание:** React обработва събитията по начин, подобен на DOM събитията, но използва camelCase за имената на събитията.
  * **Пример:**
    ```jsx
    <button onClick={handleClick}>
      Кликни ме
    </button>
    ```

* **Обработка на събития и използване на функции за събития**
  * **Описание:** Функциите за обработка на събития могат да бъдат дефинирани като методи на класа или като стрелкови функции във функционални компоненти.
  * **Пример:**
    ```jsx
    function handleClick() {
      alert('Бутонът беше натиснат!');
    }
    ```

---

**Жизнен цикъл на компонента (Component Lifecycle)**

* **Основни методи на жизнения цикъл при класови компоненти**
  * **Описание:** Класовите компоненти имат специфични методи, които се извикват в различни етапи от жизнения цикъл на компонента.
  * **Пример:**
    ```jsx
    componentDidMount() {
      // Извиква се след като компонентът е монтиран
    }

    componentWillUnmount() {
      // Извиква се преди компонентът да бъде демонтиран
    }
    ```

* **Жизнен цикъл при функционални компоненти с hooks**
  * **Описание:** Хукът `useEffect()` може да замести повечето методи на жизнения цикъл в класовите компоненти.
  * **Пример:**
    ```jsx
    useEffect(() => {
      // Кодът тук се изпълнява при монтиране и актуализиране

      return () => {
        // Кодът тук се изпълнява при демонтиране
      };
    }, []);
    ```

---

**Hooks**

* **useState и useEffect hooks**
  * **Описание:** Хукът `useState()` позволява използването на state в функционални компоненти, а `useEffect()` управлява страничните ефекти.
  * **Пример за useState:**
    ```jsx
    const [name, setName] = useState('Иван');
    ```
  * **Пример за useEffect:**
    ```jsx
    useEffect(() => {
      document.title = `Здравей, ${name}`;
    }, [name]);
    ```

* **Допълнителни hooks (useContext, useReducer, useRef, и т.н.)**
  * **Описание:** React предоставя и други hooks за специфични случаи, като контекст, референции към DOM елементи и др.
  * **Пример за useRef:**
    ```jsx
    const inputRef = useRef();

    function focusInput() {
      inputRef.current.focus();
    }
    ```

---

**Управление на формуляри**

* **Контролирани и неконтролирани компоненти**
  * **Описание:** При контролираните компоненти React управлява стойността на формовите елементи, докато при неконтролираните стойността се управлява от самия DOM.
  * **Пример за контролиран компонент:**
    ```jsx
    function Form() {
      const [value, setValue] = useState('');

      return (
        <input type="text" value={value} onChange={(e) => setValue(e.target.value)} />
      );
    }
    ```

* **Управление на формуляри и обработка на входните данни**
  * **Описание:** Обработката на събитията `onChange` и `onSubmit` позволява валидирането и изпращането на данните от формуляра.
  * **Пример:**
    ```jsx
    function handleSubmit(e) {
      e.preventDefault();
      console.log('Формулярът е изпратен:', value);
    }
    ```

---

**Маршрутизация (React Router)**

* **Добавяне на маршрути и навигация между страници**
  * **Описание:** React Router е библиотека за управление на маршрутизацията в React приложенията.
  * **Пример:**
    ```jsx
    import { BrowserRouter as Router, Route, Link } from 'react-router-dom';

    function App() {
      return (
        <Router>
          <nav>
            <Link to="/">Начало</Link>
            <Link to="/about">За нас</Link>
          </nav>
          <Route exact path="/" component={Home} />
          <Route path="/about" component={About} />
        </Router>
      );
    }
    ```

* **Динамични маршрути и параметри**
  * **Описание:** Можете да създавате маршрути с променливи параметри за динамично съдържание.
  * **Пример:**
    ```jsx
    <Route path="/users/:id" component={UserProfile} />
    ```

---

**Управление на състояние в големи приложения**

* **Context API**
  * **Описание:** Context API позволява споделянето на данни между компоненти без нужда от предаване на props през всяко ниво на дървото.
  * **Пример:**
    ```jsx
    const ThemeContext = React.createContext('light');

    function App() {
      return (
        <ThemeContext.Provider value="dark">
          <Toolbar />
        </ThemeContext.Provider>
      );
    }
    ```

* **Redux (или алтернативни библиотеки като Recoil, Zustand)**
  * **Описание:** Redux е популярна библиотека за управление на глобалното състояние в приложения с голям обем данни.
  * **Пример:**
    ```jsx
    import { createStore } from 'redux';

    function reducer(state = initialState, action) {
      // логика за промяна на състоянието
    }

    const store = createStore(reducer);
    ```

---

**Работа с API**

* **Fetching на данни от външни API**
  * **Описание:** Използването на `fetch()` или библиотеки като Axios за извличане на данни от външни източници.
  * **Пример с fetch:**
    ```jsx
    useEffect(() => {
      fetch('https://api.example.com/items')
        .then(response => response.json())
        .then(data => setItems(data));
    }, []);
    ```

* **Управление на асинхронни заявки в React компоненти**
  * **Описание:** Обработка на състояния като зареждане, успех и грешка при асинхронни операции.
  * **Пример:**
    ```jsx
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    useEffect(() => {
      fetch('...')
        .then(...)
        .catch(error => setError(error))
        .finally(() => setLoading(false));
    }, []);
    ```

---

**Оптимизация на производителността**

* **Мемоизация с React.memo и useMemo**
  * **Описание:** Мемоизацията предотвратява излишни изчисления и рендерирания чрез запаметяване на резултатите.
  * **Пример с React.memo:**
    ```jsx
    const MemoizedComponent = React.memo(function Component(props) {
      return <div>{props.value}</div>;
    });
    ```

* **Избягване на излишни рендерирания с useCallback**
  * **Описание:** Хукът `useCallback()` връща мемоизирана версия на функция, която се променя само ако някоя от зависимостите се промени.
  * **Пример:**
    ```jsx
    const handleClick = useCallback(() => {
      doSomething(a, b);
    }, [a, b]);
    ```

---

**React сървърна рендерирация (Server-Side Rendering)**

* **Въведение в Next.js или друго решение за SSR**
  * **Описание:** Next.js е фреймуърк за React, който поддържа сървърна рендерирация и генериране на статични сайтове.
  * **Пример:**
    ```jsx
    export async function getServerSideProps(context) {
      const res = await fetch(`https://.../data`);
      const data = await res.json();

      return {
        props: { data },
      };
    }

    function Page({ data }) {
      return <div>{data.title}</div>;
    }

    export default Page;
    ```

---

**Тестване на React компоненти**

* **Използване на библиотеки като Jest и React Testing Library**
  * **Описание:** Тестовете гарантират, че компонентите функционират правилно при различни условия.
  * **Пример с Jest:**
    ```jsx
    test('рендерира правилно', () => {
      const { getByText } = render(<Greeting name="Иван" />);
      expect(getByText('Здравей, Иван')).toBeInTheDocument();
    });
    ```

---

**Разширени концепции и добри практики**

* **Code splitting и lazy loading**
  * **Описание:** Разделянето на кода позволява зареждането само на необходимите части от приложението, подобрявайки производителността.
  * **Пример:**
    ```jsx
    const OtherComponent = React.lazy(() => import('./OtherComponent'));

    function MyComponent() {
      return (
        <Suspense fallback={<div>Зареждане...</div>}>
          <OtherComponent />
        </Suspense>
      );
    }
    ```

* **Error boundaries**
  * **Описание:** Компонентите за обработка на грешки прихващат JavaScript грешки в дъщерните компоненти и показват резервен UI.
  * **Пример:**
    ```jsx
    class ErrorBoundary extends React.Component {
      constructor(props) {
        super(props);
        this.state = { hasError: false };
      }

      static getDerivedStateFromError(error) {
        return { hasError: true };
      }

      render() {
        if (this.state.hasError) {
          return <h1>Нещо се обърка.</h1>;
        }

        return this.props.children;
      }
    }
    ```

* **Оптимизация и производителност**
  * **Описание:** Използвайте инструменти като Profiler за идентифициране на проблеми с производителността и оптимизиране на приложението.

---

**Допълнителни теми**

* **TypeScript с React**
  * **Описание:** TypeScript добавя статична типизация към JavaScript, което помага за предотвратяване на грешки.
  * **Пример:**
    ```tsx
    interface Props {
      name: string;
    }

    const Greeting: React.FC<Props> = ({ name }) => {
      return <h1>Здравей, {name}</h1>;
    };
    ```

* **Стилове и CSS в React**
  * **Описание:** Можете да прилагате стилове чрез CSS файлове, CSS модули, Styled Components и др.
  * **Пример със Styled Components:**
    ```jsx
    import styled from 'styled-components';

    const Button = styled.button`
      background: palevioletred;
      color: white;
    `;
    ```

* **Анимации с React**
  * **Описание:** Използване на библиотеки като Framer Motion за създаване на анимации.
  * **Пример:**
    ```jsx
    import { motion } from 'framer-motion';

    function AnimatedComponent() {
      return (
        <motion.div animate={{ x: 100 }}>
          Движещ се елемент
        </motion.div>
      );
    }
    ```

* **Управление на разрешения и автентикация**
  * **Описание:** Интеграция с системи за автентикация като JWT, OAuth и др.
  * **Пример:**
    ```jsx
    // Проверка за автентикация преди рендериране на компонент
    function PrivateRoute({ component: Component, ...rest }) {
      return (
        <Route
          {...rest}
          render={(props) =>
            isAuthenticated ? <Component {...props} /> : <Redirect to="/login" />
          }
        />
      );
    }
    ```

---
