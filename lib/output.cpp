#include <iostream>
#include <fstream>
#include <locale>
#include "../include/output.h"

general_info::~general_info() {}

void help_info::see_info()
{
    auto see_print = [](std::string value, int epmty_line = 0) -> void
    {
        (epmty_line != 0) ? (std::cout << value << std::endl << std::endl) : (std::cout << value << std::endl);
    };

    see_print("*** Визначення об'єму компонентів суслового агару з натуральної сировини ***", 1);
    see_print("Для виводу в термінал:");
    see_print("-d [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]", 1);
    see_print("Для виводу у файл:");
    see_print("-df [початкова концентрація (%)] [кінцева концентрація (%)] [об'єм фільтрату (мл)]", 1);
    see_print("Для довідки:");
    see_print("-h | --help", 1);
    see_print("Додаткова інформація:");
    see_print("-i");
}

void inf_indo::see_info()
{
     auto see_print = [](std::string value, int epmty_line = 0) -> void
    {
        (epmty_line != 0) ? (std::cout << value << std::endl << std::endl) : (std::cout << value << std::endl);
    };

    see_print("В лабораторних умовах приготування розчину заданої");
    see_print("масової чатки розчиненої речовини з розчинів");
    see_print("з відомою масовою часткою здійснюється відповідно правилу хреста:");
    see_print("m1 * W1 + m2 * W2 = W3 * (m1 + m2)", 1);
    see_print("Утиліта визначає дані:");
    see_print("- об'єм води для розведення концентрованого розчину");
    see_print("- об'єм розведеного розчину");
    see_print("виходячи з концентрації початкового розчину, об'єму фільтрата");
    see_print("і концентрації розчину, який готується");
}

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(wort_solution *wrt)
{
    std::cout << "Концентрація нерозведеного розчина: " << wrt->first_wort << " %" << std::endl;
    std::cout << "Концентрація розведеного розчина: " << wrt->finish_wort << " %" << std::endl;
    std::cout << "Об'єм фільтрата: " << wrt->vol_filtrate << " мл" << std::endl;

    solution sol;
    std::cout << "Об'єм води для розчинення: " << sol.solutions(sol.water_for_solvation)->get_solvation(*wrt) << " мл" << std::endl;
    std::cout << "Об'єм розчиненого середовища: " << sol.solutions(sol.total_volume)->get_solvation(*wrt) << " мл" << std::endl;
}

void file_info::see_info(wort_solution *wrt)
{
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
