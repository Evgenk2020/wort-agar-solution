#include <iostream>
#include <fstream>
#include <locale>
#include "../include/output.h"

#include <sstream>
#include <format>

general_info::~general_info() {}

void help_info::see_info()
{
    std::cout << R"(*** Визначення об'єму компонентів суслового агару з натуральної сировини ***

Для виводу в термінал:
-d [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]

Для виводу у файл:
-df [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]

Для довідки:
-h | --help

Додаткова інформація:
-i)" << std::endl;
}

void inf_indo::see_info()
{
    std::cout << R"(В лабораторних умовах приготування розчину заданої
масової чатки розчиненої речовини з розчинів
з відомою масовою часткою здійснюється відповідно правилу хреста:
m1 * W1 + m2 * W2 = W3 * (m1 + m2)

Утиліта визначає дані:
- об'єм води для розведення концентрованого розчину
- об'єм розведеного розчину
виходячи з концентрації початкового розчину, об'єму фільтрата
і концентрації розчину, який готується)" << std::endl;
}

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(wort_solution *wrt)
{
    solution sol;

    struct liter
    {
        std::string one, two;
    };

    liter ltt;
    ltt.one = std::format("{:.2f}", sol.solutions(sol.water_for_solvation)->get_solvation(*wrt));
    ltt.two = std::format("{:.2f}", sol.solutions(sol.total_volume)->get_solvation(*wrt));

    auto screen_line = [&wrt, &ltt]() -> std::string
    {
        return std::format(
            "Концентрація нерозведеного розчина: {}%\n"
            "Концентрація розведеного розчина: {}%\n"
            "Об'єм фільтрата: {} мл\n"
            "Об'єм води для розчинення: {} мл\n"
            "Об'єм розчиненого середовища: {} мл",
            wrt->first_wort,
            wrt->finish_wort,
            wrt->vol_filtrate,
            ltt.one,
            ltt.two
        );
    };

    std::cout << screen_line() << std::endl;
}

void file_info::see_info(wort_solution *wrt)
{
     // *****************************************************
    /* float a = 2.33f;

    auto fm_st = [](float &inp) -> std::string
    {
        std::locale ua("uk_UA.UTF-8");
        std::ostringstream oss;
        oss.imbue(ua);
        oss << inp;

        return oss.str();
    };

    std::cout << fm_st(a) << std::endl; */
    // *****************************************************

    std::ofstream writer("wort-dada.csv", std::ios::app);
    const char coma = ',';
    const char quo = '\"';

    std::locale m_loc("uk_UA.utf8");
    writer.imbue(m_loc);

    writer << quo << "Концентрація нерозведеного розчина:" << quo << coma << quo << wrt->first_wort << quo << coma << quo << "%" << quo << std::endl;
    writer << quo << "Концентрація розведеного розчина:" << quo << coma << quo << wrt->finish_wort << quo << coma << quo << "%" << quo << std::endl;
    writer << quo << "Об'єм фільтрата:" << quo << coma << quo << wrt->vol_filtrate << quo << coma << quo << "мл" << quo << std::endl;

    solution sol;

    writer << quo << "Об'єм води для розчинення:" << quo << coma << quo << sol.solutions(sol.water_for_solvation)->get_solvation(*wrt) << quo << coma << quo << "мл" << quo << std::endl;
    writer << quo << "Об'єм розчиненого середовища:" << quo << coma << quo << sol.solutions(sol.total_volume)->get_solvation(*wrt) << quo << coma << quo << "мл" << quo << std::endl;
    writer << "" << std::endl;

    std::cout << "Дані додані у файл wort-dada.csv" << std::endl;
}

//--------------------------------------------------

print_info::print_info(general_info *temp) : g_info(temp) {}
print_info::print_info(data_info *temp) : d_info(temp) {}

void print_info::_print() { g_info->see_info(); }
void print_info::_print(wort_solution temp) { d_info->see_info(&temp); }

print_info::~print_info()
{
    delete g_info;
    g_info = nullptr;

    delete d_info;
    d_info = nullptr;
}
