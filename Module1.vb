Module Module1
    Dim line As String = " " & vbCrLf & "==========================================================================================" & vbCrLf & " "
    'Переменная для выбора пользователя
    Dim choice As String
    'Процедура для вывода заставки и справки о программе
    Sub begin()
        Dim zastavka() = {"_____      _______                               ________    _______                      ",
                          "||   \     ||        ||   ||   ||       //\         ||       ||           //\     ||      ",
                          "||____|    ||_____   ||   ||   ||      //__\        ||       ||_____     //  \    ||____  ",
                          "||         ||        ||   ||   ||     //    \       ||       ||         //    \   ||    ||",
                          "||         ||_____   ||___||___||    //      \      ||       ||_____   //      \  ||____||"}
        'Вывод заставки
        For k = 0 To 25
            Console.Clear()
            For i = 0 To UBound(zastavka)
                Console.SetCursorPosition(18, k + i)
                Console.WriteLine(zastavka(i))
            Next
            If k = 7 Then
                Console.SetCursorPosition(0, 14)
                choice = vybor("Начало работы", "Справка", "                                              ")
            End If
            Pause(0.05)
        Next
        Console.Clear()
        'Вывод справки (по желанию)
        If choice = "2" Then
            Console.WriteLine(line)
            Console.WriteLine("Эта программа для подсчета результатов математических выражений." & vbCrLf &
                              "Создатель программы - Певцов Дмитрий Валерьевич." & vbCrLf &
                              "На вход она принимает строку с математическим выражением и выда-" & vbCrLf &
                              "ет его результат." & vbCrLf &
                              "Пользователь может вводить:" & vbCrLf &
                              "-Цифры от 0 до 9" & vbCrLf &
                              "-Знаки математических операций: " & vbCrLf &
                              "'+' - сложение, '-' - вычитание, '*' - умножение, '/' - деление," & vbCrLf &
                              "'^' - возведение в степень" & vbCrLf &
                              "-Знаки скобок '(' и ')'" & vbCrLf &
                              "Начать работу - (Enter)")
            Console.WriteLine(line)
            Console.ReadLine()
            Console.Clear()
        End If
    End Sub
    Sub Main()
        'Цветовая палитра программы
        Console.BackgroundColor = ConsoleColor.DarkRed
        Console.ForegroundColor = ConsoleColor.Yellow
        Console.Clear()
        'Процедура для вывода заставки и справки о программе
        begin()
        Dim oshib As String 'Переменная хранит информацию о наличии или отсутствии ошибки, и ее типе
        Dim str As String 'Переменная хранит математический пример введенный пользователем
        Dim otvet As Single 'Переменная хранит ответ
        'Ввод
        choice = "1"
        Do While choice = "1"
            oshib = "Неизвестный символ"
            'Ввод пока будут ошибки
            Do While oshib <> ""
                Console.WriteLine(line)
                Console.Write("      Введите пример: ")
                str = Console.ReadLine
                Console.WriteLine(line)
                'Очистка от пробелов
                str = str.Replace(" ", "")
                'Функция для выявление ошибок
                oshib = durak(" " & str & " ")
                If oshib <> "" Then
                    Console.WriteLine("      Ошибка!!!" & oshib & ". Попробуйте еще раз")
                    choice = vybor("Повторить", "Выйти")
                    Console.Clear()
                End If
            Loop
            'Функция для подсчета ответа
            otvet = count(str)
            Console.WriteLine("      Ответ: " & otvet)
            Console.WriteLine(line)
            'Выбор пользователя продолжить или выйти
            choice = vybor("Повторить", "Выйти")
            Console.Clear()
        Loop
        Console.ReadKey()
    End Sub
    'Функция принимает выбор пользователя и проверяет его
    Function vybor(first As String, second As String, Optional probel As String = "      ") As String
        Dim choice As String
        Console.WriteLine(probel & "1 - " & first & vbCrLf & probel & "2 - " & second)
        Dim bug = True 'Переменная хронит информацию о наличии ошибки или ее отсутствия
        Do While bug = True
            Console.Write(probel)
            choice = Console.ReadLine()
            'Случаи выбора
            If choice = "2" Then
                'Выход из программы
                If second = "Выйти" Then
                    MsgBox("Рад помочь!" & vbCrLf & "Досвидания...")
                    End
                Else Return "2"
                End If
            ElseIf choice = "1" Then
                Return "1"
                'Посторонний выбор
            Else
                Console.WriteLine(probel & "Неверное значение! Попробуйте еше раз")
            End If
        Loop
        Console.Clear()
    End Function
    'Функция для подсчета результатов математических выражений
    Function count(str As String) As Single
        str += " " 'Добавляется пробел, чтобы функция не вышла за пределы строки
        Dim ch, zn, otv, n, prom1, prom2 As Single
        Dim x As String
        Dim scob As Integer = 0
        n = 0 'n считает количество математических знаков, количество чисел на один больше
        'Подсчет количества математических знаков (вне скобок)
        For k = 0 To Len(str) - 1
            If str(k) = "+" Or str(k) = "-" Or str(k) = "*" Or str(k) = "/" Or str(k) = "^" Then
                n += 1
            ElseIf str(k) = "(" Then
                scob -= 1
                Do While scob <> 0
                    k += 1
                    If str(k) = "(" Then
                        scob -= 1
                    ElseIf str(k) = ")" Then
                        scob += 1
                    End If
                Loop
            End If
        Next
        Dim num(n) As Single 'Массив чисел
        Dim sym(n) As Char 'Массив мат. знаков
        zn = 0 'Порядковый номер мат. знака
        ch = 0 'Порядковый номер числа
        For k = 0 To Len(str) - 1
            x = ""
            Select Case str(k)
                'Выделяется отрезок строки с числом, и переводится в числовой вид
                Case "0" To "9", "."
                    Do While (str(k) >= "0") And (str(k) <= "9") Or (str(k) = ".")
                        x += str(k)
                        k += 1
                    Loop
                    k -= 1
                    num(ch) = Val(x)
                    ch += 1
                'Выделяются мат. знаки
                Case "*", "/", "+", "-", "^"
                    sym(zn) = str(k)
                    zn += 1
                'Вделяется отрезок строки в скобках и считается результат этого выражения функцией count
                Case "("
                    k += 1
                    scob -= 1
                    Do While scob <> 0
                        x += str(k)
                        k += 1
                        If str(k) = "(" Then
                            scob -= 1
                        ElseIf str(k) = ")" Then
                            scob += 1
                        End If
                    Loop
                    num(ch) = count(x)
                    ch += 1
            End Select
        Next
        sym(n) = "+" 'Добавляется еще один знак, чтобы функция не выходила за прделы массива
        otv = num(0)
        prom1 = 0 'Переменная хранит промежуточное значение перед знаком сложения или вычитания 
        prom2 = 1 'Переменная хранит промежуточное значение умножения и деления
        'Цикл проходит по каждому знаку и совершает различные операции с соседними с ним числами,
        'в зависимости от следующего знака, если следующий знак сложение или вычитание, то просто подсчитвается результат
        'в противном случае записываются результаты в промежуточные переменные
        For k = 0 To n - 1
            Select Case sym(k)
                Case "+"
                    If sym(k + 1) = "+" Or sym(k + 1) = "-" Then
                        otv += num(k + 1)
                    Else
                        prom1 = otv
                        otv = num(k + 1)
                    End If
                Case "-"
                    If sym(k + 1) = "+" Or sym(k + 1) = "-" Then
                        otv -= num(k + 1)
                    Else
                        prom1 = otv
                        otv = num(k + 1)
                        prom2 = -1
                    End If
                Case "*"
                    If sym(k + 1) = "+" Or sym(k + 1) = "-" Then
                        otv = prom1 + prom2 * otv * num(k + 1)
                        prom1 = 0
                        prom2 = 1
                    Else
                        prom2 *= otv
                        otv = num(k + 1)
                    End If
                Case "/"
                    If sym(k + 1) = "+" Or sym(k + 1) = "-" Then
                        otv = prom1 + prom2 * otv / num(k + 1)
                        prom1 = 0
                        prom2 = 1
                    Else
                        prom2 *= otv
                        otv = 1 / num(k + 1)
                    End If
                Case "^"
                    If sym(k + 1) = "+" Or sym(k + 1) = "-" Then
                        otv = prom1 + prom2 * otv ^ num(k + 1)
                        prom1 = 0
                        prom2 = 1
                    Else
                        otv = otv ^ num(k + 1)
                    End If
            End Select
        Next
        Return otv
    End Function
    'Функция паузы
    Sub Pause(z As Single)
        Dim t As Single
        t = Timer
        Do
        Loop Until Timer() - t >= z
    End Sub
    'Функция проверяет на ошибки в введенной пользователем строке
    Function durak(str As String) As String
        Dim vozm() As Char = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "+", "-", "*", "/", "^", "(", ")", " "}
        Dim bug As String = "Неизвестный символ" 'Переменная хранит ошибку, если она пустая, то ошибки - нет
        Dim scob As Integer = 0
        'Цикл проходит по каждому символу в строке и сравнивает с возможными символами
        For k = 0 To Len(str) - 1
            For i = 0 To 18
                If str(k) = vozm(i) Then
                    'Если пподобный символ возможен, то ошибки временно - нет
                    bug = ""
                    If str(k) = vozm(i) Then
                        'Проверяется правильность написания скобок
                        If i = 16 Then
                            scob -= 1
                            If str(k + 1) = ")" Then bug = "Неправильное написание в скобках"
                        End If
                        If i = 17 Then
                            scob += 1
                            If scob > 0 Then bug = "Неправильное написание в скобках"
                        End If
                        'Проверяется правильность написания мат. знаков
                        If i > 10 And i < 16 Then bug = prov_znak(str, k)
                        'Проверяется правильность написания чисел со скобками
                        If i >= 0 And i < 11 Then bug = prov_chisl_scob(str, k)
                    End If
                End If
            Next
            'Если найдена ошибка, то функция возвращает данные об этой ошибке
            If bug <> "" Then
                Return bug
            End If
            bug = "Неизвестный символ"
        Next
        If scob <> 0 Then
            Return "Неправильное написание в скобках"
        Else
            Return ""
        End If
    End Function
    'Функция проверяет правильность написания мат. знаков
    Function prov_znak(str As String, n As Integer) As String
        If str(n + 1) = "+" Or str(n + 1) = "-" Or str(n + 1) = "*" Or str(n + 1) = "/" Or str(n + 1) = "^" Or str(n + 1) = " " Or str(n - 1) = " " Then Return "Неправильное написание в знаках"
    End Function
    'Функция проверяет правильность написания чисел со скобками
    Function prov_chisl_scob(str As String, n As Integer) As String
        If str(n - 1) = ")" Or str(n + 1) = "(" Then Return "Нет знака между числом и скобкой"
    End Function
End Module
