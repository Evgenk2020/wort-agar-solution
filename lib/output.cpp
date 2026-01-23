#include "../include/output.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <print>
#include <format>
#include <vector>

void help_info::see_info()
{
    std::println(
        "*** Визначення об'єму компонентів суслового агару з натуральної сировини ***\n"
        "\n"
        "Для виводу в термінал:\n"
        "d [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]\n"
        "\n"
        "Для виводу у файл:\n"
        "-df [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]\n"
        "\n"
        "Для довідки:\n"
        "-h | --help\n"
        "\n"
        "Додаткова інформація:\n"
        "-i");
}

void inf_indo::see_info()
{
    std::println(
        "В лабораторних умовах приготування розчину заданої\n"
        "масової чатки розчиненої речовини з розчинів\n"
        "з відомою масовою часткою здійснюється відповідно правилу хреста:\n"
        "m1 * W1 + m2 * W2 = W3 * (m1 + m2)\n"
        "\n"
        "Утиліта визначає дані:\n"
        "- об'єм води для розведення концентрованого розчину\n"
        "- об'єм розведеного розчину\n"
        "виходячи з концентрації початкового розчину, об'єму фільтрата\n"
        "і концентрації розчину, який готується");
}

//--------------------------------------------------

void screen_info::see_info(wort_solution *wrt)
{
    std::cout << std::format("Концентрація нерозведеного розчина: {}%\n", wrt->first_wort);
    std::cout << std::format("Концентрація розведеного розчина: {}%\n", wrt->finish_wort);
    std::cout << std::format("Об'єм фільтрата: {} мл\n", wrt->vol_filtrate);
    std::cout << std::format("Об'єм води для розчинення: {:.2f} мл\n", sol.solutions(sol.water_for_solvation)->get_solvation(*wrt));
    std::cout << std::format("Об'єм розчиненого середовища: {:.2f} мл\n", sol.solutions(sol.total_volume)->get_solvation(*wrt));
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
