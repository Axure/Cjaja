int main() {
  LocalDateTime.now().plusDays(3).minusHours(1).format(DateTimeFormatter
                                                           .ISO_LOCAL_DATE_TIME); //输出日期和时间
  ZonedDateTime.now().withZoneSameInstant(ZoneId.of("GMT+08:00")).format
      (DateTimeFormatter.ISO_ZONED_DATE_TIME); //输出日期、时间和时区
  DateTimeFormatter.ofPattern("yyyy MM dd").parse("200101 25").
      query(TemporalQuery.localDate()); //日期的解析
}