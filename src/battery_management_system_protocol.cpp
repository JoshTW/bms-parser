// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "battery_management_system_protocol.h"
#include "kaitai/exceptions.h"

battery_management_system_protocol_t::battery_management_system_protocol_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    f_ofs_body_start = false;
    f_ofs_body_end = false;
    f_checksum_input = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::_read() {
    m_magic_start = m__io->read_bytes(1);
    if (!(magic_start() == std::string("\xDD", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\xDD", 1), magic_start(), _io(), std::string("/seq/0"));
    }
    m_cmd = m__io->read_u1();
    n__unnamed2 = true;
    if (ofs_body_start() < 0) {
        n__unnamed2 = false;
        m__unnamed2 = m__io->read_bytes(0);
    }
    switch (cmd()) {
    case battery_management_system_protocol_t::COMMANDS_READ: {
        m_body = new read_req_t(m__io, this, m__root);
        break;
    }
    case battery_management_system_protocol_t::COMMANDS_WRITE: {
        m_body = new write_req_t(m__io, this, m__root);
        break;
    }
    default: {
        m_body = new response_t(cmd(), m__io, this, m__root);
        break;
    }
    }
    n__unnamed4 = true;
    if (ofs_body_end() < 0) {
        n__unnamed4 = false;
        m__unnamed4 = m__io->read_bytes(0);
    }
    m_checksum = m__io->read_u2be();
    m_magic_end = m__io->read_bytes(1);
    if (!(magic_end() == std::string("\x77", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x77", 1), magic_end(), _io(), std::string("/seq/6"));
    }
}

battery_management_system_protocol_t::~battery_management_system_protocol_t() {
    _clean_up();
}

void battery_management_system_protocol_t::_clean_up() {
    if (!n__unnamed2) {
    }
    if (m_body) {
        delete m_body; m_body = 0;
    }
    if (!n__unnamed4) {
    }
    if (f_checksum_input) {
    }
}

battery_management_system_protocol_t::cell_voltages_t::cell_voltages_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_cells = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::cell_voltages_t::_read() {
    m_cells = new std::vector<voltage_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_cells->push_back(new voltage_t(m__io, this, m__root));
            i++;
        }
    }
}

battery_management_system_protocol_t::cell_voltages_t::~cell_voltages_t() {
    _clean_up();
}

void battery_management_system_protocol_t::cell_voltages_t::_clean_up() {
    if (m_cells) {
        for (std::vector<voltage_t*>::iterator it = m_cells->begin(); it != m_cells->end(); ++it) {
            delete *it;
        }
        delete m_cells; m_cells = 0;
    }
}

battery_management_system_protocol_t::cell_voltages_t::voltage_t::voltage_t(kaitai::kstream* p__io, battery_management_system_protocol_t::cell_voltages_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_volt = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::cell_voltages_t::voltage_t::_read() {
    m_raw = m__io->read_u2be();
}

battery_management_system_protocol_t::cell_voltages_t::voltage_t::~voltage_t() {
    _clean_up();
}

void battery_management_system_protocol_t::cell_voltages_t::voltage_t::_clean_up() {
}

double battery_management_system_protocol_t::cell_voltages_t::voltage_t::volt() {
    if (f_volt)
        return m_volt;
    m_volt = (raw() * 0.001);
    f_volt = true;
    return m_volt;
}

battery_management_system_protocol_t::read_req_t::read_req_t(kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::read_req_t::_read() {
    m_req_cmd = m__io->read_u1();
    m_len_data = m__io->read_bytes(1);
    if (!(len_data() == std::string("\x00", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x00", 1), len_data(), _io(), std::string("/types/read_req/seq/1"));
    }
}

battery_management_system_protocol_t::read_req_t::~read_req_t() {
    _clean_up();
}

void battery_management_system_protocol_t::read_req_t::_clean_up() {
}

battery_management_system_protocol_t::hardware_t::hardware_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::hardware_t::_read() {
    m_version = kaitai::kstream::bytes_to_str(m__io->read_bytes_full(), std::string("ascii"));
}

battery_management_system_protocol_t::hardware_t::~hardware_t() {
    _clean_up();
}

void battery_management_system_protocol_t::hardware_t::_clean_up() {
}

battery_management_system_protocol_t::response_t::response_t(uint8_t p_cmd, kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_cmd = p_cmd;
    m__io__raw_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::response_t::_read() {
    m_status = static_cast<battery_management_system_protocol_t::response_t::status_t>(m__io->read_u1());
    m_len_data = m__io->read_u1();
    n_data = true;
    switch (cmd()) {
    case battery_management_system_protocol_t::REGISTERS_BASIC_INFO: {
        n_data = false;
        m__raw_data = m__io->read_bytes(len_data());
        m__io__raw_data = new kaitai::kstream(m__raw_data);
        m_data = new basic_info_t(m__io__raw_data, this, m__root);
        break;
    }
    case battery_management_system_protocol_t::REGISTERS_CELL_VOLTAGES: {
        n_data = false;
        m__raw_data = m__io->read_bytes(len_data());
        m__io__raw_data = new kaitai::kstream(m__raw_data);
        m_data = new cell_voltages_t(m__io__raw_data, this, m__root);
        break;
    }
    case battery_management_system_protocol_t::REGISTERS_HARDWARE: {
        n_data = false;
        m__raw_data = m__io->read_bytes(len_data());
        m__io__raw_data = new kaitai::kstream(m__raw_data);
        m_data = new hardware_t(m__io__raw_data, this, m__root);
        break;
    }
    default: {
        m__raw_data = m__io->read_bytes(len_data());
        break;
    }
    }
}

battery_management_system_protocol_t::response_t::~response_t() {
    _clean_up();
}

void battery_management_system_protocol_t::response_t::_clean_up() {
    if (!n_data) {
        if (m__io__raw_data) {
            delete m__io__raw_data; m__io__raw_data = 0;
        }
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
}

battery_management_system_protocol_t::basic_info_t::basic_info_t(kaitai::kstream* p__io, battery_management_system_protocol_t::response_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_pack_voltage = 0;
    m_pack_current = 0;
    m_remain_cap = 0;
    m_typ_cap = 0;
    m_prod_date = 0;
    m_balance_status = 0;
    m_prot_status = 0;
    m_fet_status = 0;
    m_temps = 0;
    m__raw_temps = 0;
    m__io__raw_temps = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::_read() {
    m_pack_voltage = new voltage_t(m__io, this, m__root);
    m_pack_current = new current_t(m__io, this, m__root);
    m_remain_cap = new capacity_t(m__io, this, m__root);
    m_typ_cap = new capacity_t(m__io, this, m__root);
    m_cycles = m__io->read_u2be();
    m_prod_date = new date_t(m__io, this, m__root);
    m_balance_status = new balance_list_t(m__io, this, m__root);
    m_prot_status = new prot_list_t(m__io, this, m__root);
    m_software_version = m__io->read_u1();
    m_remain_cap_percent = m__io->read_u1();
    m_fet_status = new fet_bits_t(m__io, this, m__root);
    m_cell_count = m__io->read_u1();
    m_num_temps = m__io->read_u1();
    m__raw_temps = new std::vector<std::string>();
    m__io__raw_temps = new std::vector<kaitai::kstream*>();
    m_temps = new std::vector<temp_t*>();
    const int l_temps = num_temps();
    for (int i = 0; i < l_temps; i++) {
        m__raw_temps->push_back(m__io->read_bytes(2));
        kaitai::kstream* io__raw_temps = new kaitai::kstream(m__raw_temps->at(m__raw_temps->size() - 1));
        m__io__raw_temps->push_back(io__raw_temps);
        m_temps->push_back(new temp_t(io__raw_temps, this, m__root));
    }
}

battery_management_system_protocol_t::basic_info_t::~basic_info_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::_clean_up() {
    if (m_pack_voltage) {
        delete m_pack_voltage; m_pack_voltage = 0;
    }
    if (m_pack_current) {
        delete m_pack_current; m_pack_current = 0;
    }
    if (m_remain_cap) {
        delete m_remain_cap; m_remain_cap = 0;
    }
    if (m_typ_cap) {
        delete m_typ_cap; m_typ_cap = 0;
    }
    if (m_prod_date) {
        delete m_prod_date; m_prod_date = 0;
    }
    if (m_balance_status) {
        delete m_balance_status; m_balance_status = 0;
    }
    if (m_prot_status) {
        delete m_prot_status; m_prot_status = 0;
    }
    if (m_fet_status) {
        delete m_fet_status; m_fet_status = 0;
    }
    if (m__raw_temps) {
        delete m__raw_temps; m__raw_temps = 0;
    }
    if (m__io__raw_temps) {
        for (std::vector<kaitai::kstream*>::iterator it = m__io__raw_temps->begin(); it != m__io__raw_temps->end(); ++it) {
            delete *it;
        }
        delete m__io__raw_temps; m__io__raw_temps = 0;
    }
    if (m_temps) {
        for (std::vector<temp_t*>::iterator it = m_temps->begin(); it != m_temps->end(); ++it) {
            delete *it;
        }
        delete m_temps; m_temps = 0;
    }
}

battery_management_system_protocol_t::basic_info_t::fet_bits_t::fet_bits_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::fet_bits_t::_read() {
    m_reserved = m__io->read_bits_int_be(6);
    m_is_discharge_enabled = m__io->read_bits_int_be(1);
    m_is_charge_enabled = m__io->read_bits_int_be(1);
}

battery_management_system_protocol_t::basic_info_t::fet_bits_t::~fet_bits_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::fet_bits_t::_clean_up() {
}

battery_management_system_protocol_t::basic_info_t::prot_list_t::prot_list_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::prot_list_t::_read() {
    m_reserved = m__io->read_bits_int_be(3);
    m_is_fet_lock = m__io->read_bits_int_be(1);
    m_is_ic_error = m__io->read_bits_int_be(1);
    m_is_ocp_short = m__io->read_bits_int_be(1);
    m_is_ocp_discharge = m__io->read_bits_int_be(1);
    m_is_ocp_charge = m__io->read_bits_int_be(1);
    m_is_utp_discharge = m__io->read_bits_int_be(1);
    m_is_otp_discharge = m__io->read_bits_int_be(1);
    m_is_utp_charge = m__io->read_bits_int_be(1);
    m_is_otp_charge = m__io->read_bits_int_be(1);
    m_is_uvp_pack = m__io->read_bits_int_be(1);
    m_is_ovp_pack = m__io->read_bits_int_be(1);
    m_is_uvp_cell = m__io->read_bits_int_be(1);
    m_is_ovp_cell = m__io->read_bits_int_be(1);
}

battery_management_system_protocol_t::basic_info_t::prot_list_t::~prot_list_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::prot_list_t::_clean_up() {
}

battery_management_system_protocol_t::basic_info_t::date_t::date_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_year = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::date_t::_read() {
    m_year_after_2000 = m__io->read_bits_int_be(7);
    m_month = m__io->read_bits_int_be(4);
    if (!(month() >= 1)) {
        throw kaitai::validation_less_than_error<uint64_t>(1, month(), _io(), std::string("/types/basic_info/types/date/seq/1"));
    }
    if (!(month() <= 12)) {
        throw kaitai::validation_greater_than_error<uint64_t>(12, month(), _io(), std::string("/types/basic_info/types/date/seq/1"));
    }
    m_day = m__io->read_bits_int_be(5);
    if (!(day() >= 1)) {
        throw kaitai::validation_less_than_error<uint64_t>(1, day(), _io(), std::string("/types/basic_info/types/date/seq/2"));
    }
    if (!(day() <= 31)) {
        throw kaitai::validation_greater_than_error<uint64_t>(31, day(), _io(), std::string("/types/basic_info/types/date/seq/2"));
    }
}

battery_management_system_protocol_t::basic_info_t::date_t::~date_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::date_t::_clean_up() {
}

int32_t battery_management_system_protocol_t::basic_info_t::date_t::year() {
    if (f_year)
        return m_year;
    m_year = (2000 + year_after_2000());
    f_year = true;
    return m_year;
}

battery_management_system_protocol_t::basic_info_t::temp_t::temp_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_celsius = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::temp_t::_read() {
    m_raw = m__io->read_u2be();
}

battery_management_system_protocol_t::basic_info_t::temp_t::~temp_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::temp_t::_clean_up() {
}

double battery_management_system_protocol_t::basic_info_t::temp_t::celsius() {
    if (f_celsius)
        return m_celsius;
    m_celsius = ((raw() * 0.1) - 273.1);
    f_celsius = true;
    return m_celsius;
}

battery_management_system_protocol_t::basic_info_t::current_t::current_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_amp = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::current_t::_read() {
    m_raw = m__io->read_s2be();
}

battery_management_system_protocol_t::basic_info_t::current_t::~current_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::current_t::_clean_up() {
}

double battery_management_system_protocol_t::basic_info_t::current_t::amp() {
    if (f_amp)
        return m_amp;
    m_amp = (raw() * 0.01);
    f_amp = true;
    return m_amp;
}

battery_management_system_protocol_t::basic_info_t::voltage_t::voltage_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_volt = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::voltage_t::_read() {
    m_raw = m__io->read_u2be();
}

battery_management_system_protocol_t::basic_info_t::voltage_t::~voltage_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::voltage_t::_clean_up() {
}

double battery_management_system_protocol_t::basic_info_t::voltage_t::volt() {
    if (f_volt)
        return m_volt;
    m_volt = (raw() * 0.01);
    f_volt = true;
    return m_volt;
}

battery_management_system_protocol_t::basic_info_t::balance_list_t::balance_list_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_is_balancing = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::balance_list_t::_read() {
    m_is_balancing = new std::vector<bool>();
    const int l_is_balancing = 32;
    for (int i = 0; i < l_is_balancing; i++) {
        m_is_balancing->push_back(m__io->read_bits_int_be(1));
    }
}

battery_management_system_protocol_t::basic_info_t::balance_list_t::~balance_list_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::balance_list_t::_clean_up() {
    if (m_is_balancing) {
        delete m_is_balancing; m_is_balancing = 0;
    }
}

battery_management_system_protocol_t::basic_info_t::capacity_t::capacity_t(kaitai::kstream* p__io, battery_management_system_protocol_t::basic_info_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_amp_hour = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::basic_info_t::capacity_t::_read() {
    m_raw = m__io->read_u2be();
}

battery_management_system_protocol_t::basic_info_t::capacity_t::~capacity_t() {
    _clean_up();
}

void battery_management_system_protocol_t::basic_info_t::capacity_t::_clean_up() {
}

double battery_management_system_protocol_t::basic_info_t::capacity_t::amp_hour() {
    if (f_amp_hour)
        return m_amp_hour;
    m_amp_hour = (raw() * 0.01);
    f_amp_hour = true;
    return m_amp_hour;
}

battery_management_system_protocol_t::write_req_t::write_req_t(kaitai::kstream* p__io, battery_management_system_protocol_t* p__parent, battery_management_system_protocol_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void battery_management_system_protocol_t::write_req_t::_read() {
    m_req_cmd = m__io->read_u1();
    m_len_write_data = m__io->read_u1();
    m_write_data = m__io->read_bytes(len_write_data());
}

battery_management_system_protocol_t::write_req_t::~write_req_t() {
    _clean_up();
}

void battery_management_system_protocol_t::write_req_t::_clean_up() {
}

int32_t battery_management_system_protocol_t::ofs_body_start() {
    if (f_ofs_body_start)
        return m_ofs_body_start;
    m_ofs_body_start = _io()->pos();
    f_ofs_body_start = true;
    return m_ofs_body_start;
}

int32_t battery_management_system_protocol_t::ofs_body_end() {
    if (f_ofs_body_end)
        return m_ofs_body_end;
    m_ofs_body_end = _io()->pos();
    f_ofs_body_end = true;
    return m_ofs_body_end;
}

std::string battery_management_system_protocol_t::checksum_input() {
    if (f_checksum_input)
        return m_checksum_input;
    std::streampos _pos = m__io->pos();
    m__io->seek(ofs_body_start());
    m_checksum_input = m__io->read_bytes((ofs_body_end() - ofs_body_start()));
    m__io->seek(_pos);
    f_checksum_input = true;
    return m_checksum_input;
}
